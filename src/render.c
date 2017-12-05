/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:59:54 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/05 17:54:16 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

#include <stdio.h>
void			print_vec(char *tag, t_vec3d vec)
{
	printf("%s = { %lf, %lf, %lf }\n", tag, vec.x, vec.y, vec.z);
}

t_obj			*throw_ray_get_hit_obj(t_scene scene, t_ray ray, double *t)
{
	t_obj		*obj_nearest;
	double		t_nearest;
	t_obj		*obj_cur;

	obj_nearest = NULL;
	t_nearest = 1000000000;
	obj_cur = (t_obj*)ft_vector_begin(&scene.objs);
	while (++obj_cur < (t_obj*)ft_vector_end(&scene.objs))
	{
		if (obj_ray_hit(obj_cur, ray, t) && *t < t_nearest)
		{
			obj_nearest = obj_cur;
			t_nearest = *t;
		}
	}
	*t = t_nearest;
	return (obj_nearest);
}

static t_vec3d	get_light_dir(t_scene scene, t_vec3d pt, t_clrf_rgb *light_c
		, double *dist)
{
	t_vec3d		light_dir;
	double		r2;
	int			directionnal;
	double		div;

	directionnal = 0;
	light_dir = ft_vec3d_sub(scene.light_pos, pt);
	r2 = ft_vec3d_dot(light_dir, light_dir);
	*dist = sqrt(r2);
	if (directionnal)
	{
		*dist = 20000;
		light_dir = ft_vec3d_norm(ft_vec3d(1, -1, 2));
		div = 100;
	}
	else
	{
		light_dir = ft_vec3d_div_by(light_dir, *dist);
		div = 4 * M_PI * r2;
	}
	*light_c = ft_clrf_rgb(
		scene.light_i * scene.light_c.r / div
		, scene.light_i * scene.light_c.g / div
		, scene.light_i * scene.light_c.b / div);

	return (light_dir);
}

t_clrf_rgb		throw_ray_get_color(t_scene scene, t_ray ray)
{
	t_vec3d		hit_pos;
	double		diffuse;
	t_vec3d		d_to_light;
	t_clrf_rgb	color;
	double		t;
	t_obj		*obj;
	t_obj		*obj_sh;
	t_clrf_rgb	obj_c;
	t_clrf_rgb	lig_c;

	if ((obj = throw_ray_get_hit_obj(scene, ray, &t)))
	{
		hit_pos = ft_vec3d_add(ray.orig, ft_vec3d_scale(ray.dir, t));
		d_to_light = get_light_dir(scene, hit_pos, &lig_c, &t);
		diffuse = MAX(0, ft_vec3d_dot(d_to_light, obj_normal(obj, hit_pos)));
		diffuse = MIN(1, diffuse);
		obj_c = obj_surface_color(obj, hit_pos);
		color = ft_clrf_rgb_mult(scene.amb_c, obj_c);
		ray.dir = d_to_light;
		ray.orig = ft_vec3d_add(hit_pos, ft_vec3d_scale(ray.dir, 1e-5));
		obj_sh = throw_ray_get_hit_obj(scene, ray, &t);
		hit_pos = ft_vec3d_add(ray.orig, ft_vec3d_scale(ray.dir, t));
		if (!obj_sh && ft_vec3d_dot(d_to_light, ft_vec3d_sub(hit_pos, scene.light_pos)) > 0)
		{
			color = ft_clrf_rgb_add(color
					, ft_clrf_rgb_scale(ft_clrf_rgb_mult(lig_c, obj_c)
						, diffuse * scene.diffuse));
		}
		color = ft_clrf_rgb_clamp(color);
	}
	else
		color = ft_clrf_rgb(0, 0, 0);
	return (color);
}

void			render(t_app *app)
{
	t_scene			scene;
	t_camera		cam;
	int				width = app->draw_buf.width;
	int				height = app->draw_buf.height;
	double			pxl_ratio;
	t_vec3d			rot;
	t_obj			obj_new;
	t_vec3d			off;

	cam = cam_create();

	scene.amb_c = ft_clrf_rgb(0.15, 0.15, 0.15);
	scene.diffuse = 0.85;


	scene.light_c = ft_clrf_rgb(1, 1, 1);

	scene.objs = ft_vector_create(sizeof(t_obj), NULL, NULL);
(void)off;
#define SCENE 1

#if SCENE == 0
/* MOLECULES SCENE ========================================================= */

	obj_new = obj_sphere(ft_vec3d(0, 0, 1), 0.4, ft_clrf_rgb(0.1, 0.1, 0.1));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_sphere(ft_vec3d(0.15, 0.15, 1), 0.35, ft_clrf_rgb(1, 0, 0));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_sphere(ft_vec3d(-0.15, -0.15, 1), 0.35, ft_clrf_rgb(1, 0, 0));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	off = ft_vec3d(-2, 0.75, 2);
	obj_new = obj_sphere(ft_vec3d(off.x + 0, off.y + 0, off.z + 1), 0.4, ft_clrf_rgb(0.8, 0, 0));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_sphere(ft_vec3d(off.x + 0.25, off.y - 0.25, off.z + 1), 0.3, ft_clrf_rgb(0.8, 0.8, 0.8));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_sphere(ft_vec3d(off.x + -0.25, off.y - 0.25, off.z + 1), 0.3, ft_clrf_rgb(0.8, 0.8, 0.8));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_sphere(ft_vec3d(-5, 10, 1), 0.4, ft_clrf_rgb(0, 0.8, 0));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_plane(ft_vec3d(0, 0, 5), ft_vec3d(0, 0, -1), ft_clrf_rgb(1, 1, 1));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_plane(ft_vec3d(0, -2, 0), ft_vec3d(0, 1, 0), ft_clrf_rgb(0.5, 0.5, 0.7));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_sphere();
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;

	scene.light_pos = ft_vec3d(0, 5, -5);
	scene.light_i = 500;

	cam = cam_create();
	cam.pos = ft_vec3d_sub(ft_vec3d(0, 0, 0), ft_vec3d_scale(cam.dir, 10));
	cam_set_view_rect(&cam, ft_vec2i(0, 0), ft_vec2i(width / 2, height), 1);
	cam_render_to_image(cam, scene, &app->draw_buf);

	cam = cam_create();
	cam.pos = ft_vec3d(-4, 1, 3);
	cam.dir = ft_vec3d(1, 0, 0);
	cam.right = ft_vec3d(0, 0, -1);
	cam_set_view_rect(&cam, ft_vec2i(width / 2, 0), ft_vec2i(width / 2, height), 1);
	cam_render_to_image(cam, scene, &app->draw_buf);

#elif SCENE == 1
/* CYLINDERS SCENE ========================================================= */

	pxl_ratio = 1. / 1;

	obj_new = obj_cylinder(ft_vec3d(-2.5, 2, 0), ft_vec3d_norm(ft_vec3d(0.5, -0.5, 0)), 0.2, ft_clrf_rgb(0.8, 0.8, 0));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_cylinder(ft_vec3d(0, -8, 0), ft_vec3d_norm(ft_vec3d(1, 0, 0)), 3.35, ft_clrf_rgb(1, 0.5, 0));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_cylinder(ft_vec3d(0, 8, 0), ft_vec3d_norm(ft_vec3d(1, 0, 0)), 3.35, ft_clrf_rgb(1, 0.5, 0.8));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_cylinder(ft_vec3d(1, 0, 0), ft_vec3d_norm(ft_vec3d(1, 0, 0)), 0.35, ft_clrf_rgb(1, 0, 0));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_cylinder(ft_vec3d(0, 0, 0), ft_vec3d_norm(ft_vec3d(0, 1, 0)), 0.8, ft_clrf_rgb(0, 0.8, 0));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;
	obj_new = obj_plane(ft_vec3d(0, 0, 0), ft_vec3d_rot(ft_vec3d(0, 0, -1), 0, 0, 0), ft_clrf_rgb(0.5, 0.5, 0.8));
	if (!ft_vector_push_back(&scene.objs, (char*)&obj_new))
		return ;

	/*
	scene.light_pos = ft_vec3d(-6, 4, -5);
	*/
	scene.light_pos = ft_vec3d(0, 0, -5);
	scene.light_i = 400;

	cam.pos = ft_vec3d_sub(ft_vec3d(0, 0, 0), ft_vec3d_scale(cam.dir, 10));
	cam_set_view_rect(&cam, ft_vec2i(0, 0), ft_vec2i(width / 2, height / 2), pxl_ratio);
	cam_render_to_image(cam, scene, &app->draw_buf);

	cam = cam_create();
	rot = ft_vec3d(0, M_PI / 3, 0);
	cam.dir = ft_vec3d_norm(ft_vec3d_rot(cam.dir, rot.x, rot.y, rot.z));
	cam.right = ft_vec3d_norm(ft_vec3d_rot(cam.right, rot.x, rot.y, rot.z));
	cam.up = ft_vec3d_norm(ft_vec3d_rot(cam.up, rot.x, rot.y, rot.z));
	cam.pos = ft_vec3d_sub(ft_vec3d(0, 0, 0), ft_vec3d_scale(cam.dir, 10));
	cam_set_view_rect(&cam, ft_vec2i(width / 2, 0), ft_vec2i(width / 2, height / 2), pxl_ratio);
	cam_render_to_image(cam, scene, &app->draw_buf);

	cam = cam_create();
	rot = ft_vec3d(M_PI / 3, 0, 0);
	cam.dir = ft_vec3d_norm(ft_vec3d_rot(cam.dir, rot.x, rot.y, rot.z));
	cam.right = ft_vec3d_norm(ft_vec3d_rot(cam.right, rot.x, rot.y, rot.z));
	cam.up = ft_vec3d_norm(ft_vec3d_rot(cam.up, rot.x, rot.y, rot.z));
	cam.pos = ft_vec3d_sub(ft_vec3d(0, 0, 0), ft_vec3d_scale(cam.dir, 10));
	cam_set_view_rect(&cam, ft_vec2i(0, height / 2), ft_vec2i(width / 2, height / 2), pxl_ratio);
	cam_render_to_image(cam, scene, &app->draw_buf);

	cam = cam_create();
	rot = ft_vec3d(0, M_PI / 2, 0);
	cam.dir = ft_vec3d_norm(ft_vec3d_rot(cam.dir, rot.x, rot.y, rot.z));
	cam.right = ft_vec3d_norm(ft_vec3d_rot(cam.right, rot.x, rot.y, rot.z));
	cam.up = ft_vec3d_norm(ft_vec3d_rot(cam.up, rot.x, rot.y, rot.z));
	cam.pos = ft_vec3d_sub(ft_vec3d(0, 0, 0), ft_vec3d_scale(cam.dir, 5));
	cam_set_view_rect(&cam, ft_vec2i(width / 2, height / 2), ft_vec2i(width / 2, height / 2), pxl_ratio);
	cam_render_to_image(cam, scene, &app->draw_buf);

#endif
/* END SCENES ================================================================= */
	image_put(&app->draw_buf, 0, 0);
}
