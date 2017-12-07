/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:38:51 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/05 17:49:31 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		obj_plane(t_vec3d orig, t_vec3d normal, t_clrf_rgb color)
{
	t_obj		obj;

	obj.type = obj_type_plane;
	obj.as.plane.orig = orig;
	obj.as.plane.normal = normal;
	obj.as.plane.color = color;
	return (obj);
}

int				obj_plane_ray_hit(t_plane *plane, t_ray ray, double *t)
{
	double		denom;

	denom = ft_vec3d_dot(plane->normal, ray.dir);
	if (ABS(denom) < 1e-10)
		return (0);
	*t = ft_vec3d_dot(
			ft_vec3d_sub(plane->orig, ray.orig)
			, plane->normal) / denom;
	return (*t >= 0);
}

t_vec3d			obj_plane_normal(t_plane *plane, t_vec3d pt)
{
	(void)pt;
	return (plane->normal);
}
