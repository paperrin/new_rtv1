/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 23:02:31 by paperrin          #+#    #+#             */
/*   Updated: 2017/11/30 18:10:52 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				obj_ray_hit(t_obj *obj, t_ray ray, double *t)
{
	if (obj->type == obj_type_sphere)
		return (obj_sphere_ray_hit((t_sphere*)(obj->o), ray, t));
	else if (obj->type == obj_type_plane)
		return (obj_plane_ray_hit((t_plane*)(obj->o), ray, t));
	else if (obj->type == obj_type_cylinder)
		return (obj_cylinder_ray_hit((t_cylinder*)(obj->o), ray, t));
	return (0);
}

t_vec3d			obj_normal(t_obj *obj, t_vec3d pt)
{
	if (obj->type == obj_type_sphere)
		return (obj_sphere_normal((t_sphere*)(obj->o), pt));
	else if (obj->type == obj_type_plane)
		return (obj_plane_normal((t_plane*)(obj->o), pt));
	else if (obj->type == obj_type_cylinder)
		return (obj_cylinder_normal((t_cylinder*)(obj->o), pt));
	return (ft_vec3d(0, 0, 0));
}

t_clrf_rgb		obj_surface_color(t_obj *obj, t_vec3d pt)
{
	(void)pt;
	if (obj->type == obj_type_sphere)
		return (((t_sphere*)(obj->o))->color);
	else if (obj->type == obj_type_plane)
		return (((t_plane*)(obj->o))->color);
	else if (obj->type == obj_type_cylinder)
		return (((t_cylinder*)(obj->o))->color);
	return (ft_clrf_rgb(0, 0, 0));
}
