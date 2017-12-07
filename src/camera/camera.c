/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:46:00 by paperrin          #+#    #+#             */
/*   Updated: 2017/11/30 19:45:47 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_camera		cam_create(void)
{
	t_camera	cam;

	cam.pos = ft_vec3d(0, 0, 0);
	cam.size = ft_vec3d(1, 1, 1);
	cam.dir = ft_vec3d(0, 0, 1);
	cam.up = ft_vec3d(0, 1, 0);
	cam.right = ft_vec3d(1, 0, 0);
	cam.px_pos = ft_vec2i(0, 0);
	cam.px_size = ft_vec2i(0, 0);
	cam.px_ratio = 1;
	return (cam);
}

void			cam_set_view_rect(t_camera *cam, t_vec2i px_pos, t_vec2i px_size
		, double px_ratio)
{
	cam->px_pos = px_pos;
	cam->px_size = px_size;
	cam->px_ratio = px_ratio;
	cam->size = ft_vec3d(1, 1 * (double)px_size.y / px_size.x, cam->size.z);
}

t_ray			cam_ray(t_camera cam, t_vec2i lpx)
{
	t_ray		ray;
	t_vec3d		dir_top_left;
	t_vec3d		up_step;
	t_vec3d		right_step;

	ray.orig = cam.pos;
	up_step = ft_vec3d_scale(cam.up
			, cam.size.y / ((double)cam.px_size.y / cam.px_ratio));
	right_step = ft_vec3d_scale(cam.right
			, cam.size.x / ((double)cam.px_size.x / cam.px_ratio));
	dir_top_left = ft_vec3d_add(ft_vec3d_scale(cam.dir, cam.size.z)
			, ft_vec3d_sub(ft_vec3d_scale(cam.up, cam.size.y / 2)
			, ft_vec3d_scale(cam.right, cam.size.x / 2)));
	dir_top_left = ft_vec3d_add(dir_top_left
			, ft_vec3d_sub(
				ft_vec3d_scale(right_step, 0.5)
				, ft_vec3d_scale(up_step, 0.5)));
	ray.dir = ft_vec3d_add(dir_top_left, ft_vec3d_add(
			ft_vec3d_scale(up_step, -lpx.y)
			, ft_vec3d_scale(right_step, lpx.x)));
	ray.dir = ft_vec3d_norm(ray.dir);
	return (ray);
}
