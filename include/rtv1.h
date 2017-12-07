/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:34:16 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/07 14:29:36 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include "window.h"
# include "image.h"
# include "libft.h"
# include "ft_math.h"
# include "ft_color.h"
# include "ft_vector.h"

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef enum		e_obj_type
{
	obj_type_plane = 0,
	obj_type_sphere = 1,
	obj_type_cylinder = 2,
	obj_type_cone = 3
}					t_obj_type;

typedef struct		s_app
{
	t_window	win;
	t_image		draw_buf;
	t_vec2i		size;
}					t_app;

typedef struct		s_recti
{
	int			x;
	int			y;
	int			w;
	int			h;
}					t_recti;

typedef struct		s_ray
{
	t_vec3d		orig;
	t_vec3d		dir;
}					t_ray;

typedef struct		s_sphere
{
	t_vec3d		orig;
	double		radius;
	t_clrf_rgb	color;
}					t_sphere;

typedef struct		s_cylinder
{
	t_vec3d		dir;
	t_vec3d		orig;
	double		radius;
	t_clrf_rgb	color;
}					t_cylinder;

typedef struct		s_plane
{
	t_vec3d		orig;
	t_vec3d		normal;
	t_clrf_rgb	color;
}					t_plane;

typedef union		u_obj_container
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plane		plane;
}					t_obj_container;

typedef struct		s_obj
{
	t_obj_type			type;
	t_obj_container		as;
}					t_obj;

typedef struct		s_scene
{
	t_vector	objs;
	int			nb_spheres;
	t_vec3d		light_pos;
	t_clrf_rgb	light_c;
	double		light_i;
	t_clrf_rgb	amb_c;
	double		diffuse;
}					t_scene;

typedef struct		s_camera
{
	int			should_update;
	t_vec3d		pos;
	t_vec3d		size;
	t_vec3d		dir;
	t_vec3d		up;
	t_vec3d		right;
	t_vec2i		px_pos;
	t_vec2i		px_size;
	double		px_ratio;
}					t_camera;

/*
** TODO : DELETE
*/
void				print_vec(char *tag, t_vec3d vec);

void				destroy_app(t_app *app, int exit_code);
void				render(t_app *app);

void				f_callback_loop(void *user_ptr);
void				f_callback_key(void *user_ptr, int key, int action);

t_camera			cam_create(void);
void				cam_set_view_rect(t_camera *cam, t_vec2i px_pos
		, t_vec2i px_size, double px_ratio);
t_ray				cam_ray(t_camera cam, t_vec2i lpx);
void				cam_render_to_image(t_camera cam, t_scene scene
		, t_image *image);

double				solve_quadratic(double *abc, double *values);

t_obj				*obj_new(t_obj_type type, void *o);
void				obj_free(void **obj);
int					obj_ray_hit(t_obj *obj, t_ray ray, double *t);
t_vec3d				obj_normal(t_obj *obj, t_vec3d pt);
t_clrf_rgb			obj_surface_color(t_obj *obj, t_vec3d pt);

t_obj				obj_sphere(t_vec3d orig, double radius
		, t_clrf_rgb color);
int					obj_sphere_ray_hit(t_sphere *sphere, t_ray ray, double *t);
t_vec3d				obj_sphere_normal(t_sphere *sphere, t_vec3d p);

t_obj				obj_cylinder(t_vec3d orig, t_vec3d dir, double radius
		, t_clrf_rgb color);
int					obj_cylinder_ray_hit(t_cylinder *cyl, t_ray ray, double *t);
t_vec3d				obj_cylinder_normal(t_cylinder *cyl, t_vec3d p);

t_obj				obj_plane(t_vec3d orig, t_vec3d normal
		, t_clrf_rgb color);
int					obj_plane_ray_hit(t_plane *plane, t_ray ray, double *t);
t_vec3d				obj_plane_normal(t_plane *plane, t_vec3d pt);

t_obj				*throw_ray_get_hit_obj(t_scene scene, t_ray ray, double *t);
t_clrf_rgb			throw_ray_get_color(t_scene scene, t_ray ray);

#endif
