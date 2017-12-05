/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:02:31 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/05 17:53:46 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				obj_ray_hit(t_obj *obj, t_ray ray, double *t)
{
	if (obj->type == obj_type_sphere)
		return (obj_sphere_ray_hit(&obj->as.sphere, ray, t));
	else if (obj->type == obj_type_plane)
		return (obj_plane_ray_hit(&obj->as.plane, ray, t));
	else if (obj->type == obj_type_cylinder)
		return (obj_cylinder_ray_hit(&obj->as.cylinder, ray, t));
	return (0);
}

t_vec3d			obj_normal(t_obj *obj, t_vec3d pt)
{
	if (obj->type == obj_type_sphere)
		return (obj_sphere_normal(&obj->as.sphere, pt));
	else if (obj->type == obj_type_plane)
		return (obj_plane_normal(&obj->as.plane, pt));
	else if (obj->type == obj_type_cylinder)
		return (obj_cylinder_normal(&obj->as.cylinder, pt));
	return (ft_vec3d(0, 0, 0));
}

t_clrf_rgb		obj_surface_color(t_obj *obj, t_vec3d pt)
{
	(void)pt;
	if (obj->type == obj_type_sphere)
		return (obj->as.sphere.color);
	else if (obj->type == obj_type_plane)
		return (obj->as.plane.color);
	else if (obj->type == obj_type_cylinder)
		return (obj->as.cylinder.color);
	return (ft_clrf_rgb(0, 0, 0));
}
