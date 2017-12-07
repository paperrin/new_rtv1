/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:38:51 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/05 17:47:14 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		obj_sphere(t_vec3d orig, double radius, t_clrf_rgb color)
{
	t_obj		obj;

	obj.type = obj_type_sphere;
	obj.as.sphere.orig = orig;
	obj.as.sphere.radius = radius;
	obj.as.sphere.color = color;
	return (obj);
}

int				obj_sphere_ray_hit(t_sphere *sphere, t_ray ray, double *t)
{
	t_vec3d		dist;
	double		abc[3];
	double		hits[2];

	dist = ft_vec3d_sub(ray.orig, sphere->orig);
	abc[0] = ft_vec3d_dot(ray.dir, ray.dir);
	abc[1] = 2 * ft_vec3d_dot(ray.dir, dist);
	abc[2] = ft_vec3d_dot(dist, dist) - (sphere->radius * sphere->radius);
	if (solve_quadratic(abc, hits) < 0 || hits[0] < 0)
		return (0);
	*t = hits[0];
	return (1);
}

t_vec3d			obj_sphere_normal(t_sphere *sphere, t_vec3d pt)
{
	return (ft_vec3d_div_by(ft_vec3d_sub(pt, sphere->orig), sphere->radius));
}
