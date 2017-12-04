/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:34:41 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/04 20:20:27 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Undersampled pixel ( one ray for several pixels )
** lpx_rect.{x, y} contains cast ray's coordinates on the plane
** lpx_rect.{w, h} contains number of pixels for the ray
*/
static void		cam_render_undersampled_lpixel(t_camera cam, t_scene scene
	, t_image *image, t_recti lpx_rect)
{
	t_vec2i		ppx;
	t_vec2i		off;
	t_clrf_rgb	color;

	color = throw_ray_get_color(scene
		, cam_ray(cam, ft_vec2i(lpx_rect.x, lpx_rect.y)));
	ppx = ft_vec2i(cam.px_pos.x + lpx_rect.x * cam.px_ratio
			, cam.px_pos.y + lpx_rect.y * cam.px_ratio);
	off.y = -1;
	while (++off.y < lpx_rect.h && ppx.y + off.y < (long int)image->height)
	{
		off.x = -1;
		while (++off.x < lpx_rect.w && ppx.x + off.x < (long int)image->width)
		{
			image_set_pixel(image, ppx.x + off.x, ppx.y + off.y, color);
		}
	}
}

/*
** Supersampled pixel ( several rays for one single pixel )
** lpx_rect.{x, y} contains screen pixel coordinates
** lpx_rect.{w, h} contains number of rays in the pixel
*/
static void		cam_render_supersampled_lpixel(t_camera cam, t_scene scene
	, t_image *image, t_recti lpx_rect)
{
	t_vec2i		lpx;
	t_vec2i		off;
	t_clrf_rgb	color;
	int			nb_samples;

	color = ft_clrf_rgb(0, 0, 0);
	lpx = ft_vec2i(lpx_rect.x * lpx_rect.w, lpx_rect.y * lpx_rect.h);
	off.y = -1;
	while (++off.y < lpx_rect.h)
	{
		off.x = -1;
		while (++off.x < lpx_rect.w)
		{
			color = ft_clrf_rgb_add(color, throw_ray_get_color(scene
				, cam_ray(cam, ft_vec2i(lpx.x + off.x, lpx.y + off.y))));
		}
	}
	lpx_rect.x += cam.px_pos.x;
	lpx_rect.y += cam.px_pos.y;
	nb_samples = lpx_rect.w * lpx_rect.h;
	color = ft_clrf_rgb_div_by(color, nb_samples);
	image_set_pixel(image, lpx_rect.x, lpx_rect.y, color);
}

void			cam_render_to_image(t_camera cam, t_scene scene
	, t_image *image)
{
	t_recti		lpx_rect;
	t_vec2i		cropped_size;
	int			is_supersampled;
	double		ppx_per_lpx;

	is_supersampled = cam.px_ratio < 1;
	ppx_per_lpx = (is_supersampled) ? 1 : cam.px_ratio;
	lpx_rect.w = (is_supersampled) ? 1 / cam.px_ratio : cam.px_ratio;
	lpx_rect.h = lpx_rect.w;
	cropped_size.x = (cam.px_pos.x + cam.px_size.x > (long int)image->width)
		? image->width - cam.px_pos.x : cam.px_size.x;
	cropped_size.y = (cam.px_pos.y + cam.px_size.y > (long int)image->height)
		? image->height - cam.px_pos.y : cam.px_size.y;
	lpx_rect.y = -1;
	while (++lpx_rect.y < cropped_size.y / ppx_per_lpx)
	{
		lpx_rect.x = -1;
		while (++lpx_rect.x < cropped_size.x / ppx_per_lpx)
		{
			if (!is_supersampled)
				cam_render_undersampled_lpixel(cam, scene, image, lpx_rect);
			else
				cam_render_supersampled_lpixel(cam, scene, image, lpx_rect);
		}
	}
}
