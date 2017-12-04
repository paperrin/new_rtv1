/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:12:23 by paperrin          #+#    #+#             */
/*   Updated: 2017/11/30 19:20:21 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		*obj_cylinder_new(t_vec3d orig, t_vec3d dir, double radius
		, t_clrf_rgb color)
{
	t_cylinder	*cyl;

	if (!(cyl = (t_cylinder*)malloc(sizeof(*cyl))))
		return (NULL);
	cyl->orig = orig;
	cyl->dir = dir;
	cyl->radius = radius;
	cyl->color = color;
	return (obj_new(obj_type_cylinder, cyl));
}

int				obj_cylinder_ray_hit(t_cylinder *cyl, t_ray ray, double *t)
{
	t_vec3d		cd_min_co;
	t_vec3d		axis_xy[2];
	double		abc[3];
	double		hits[2];
	t_vec3d		dist;

	dist = ft_vec3d_sub(cyl->orig, cyl->dir);
	cd_min_co = ft_vec3d_sub(dist, cyl->orig);
	axis_xy[0] = ft_vec3d_cross(ft_vec3d_sub(ray.orig, cyl->orig), cd_min_co);
	axis_xy[1] = ft_vec3d_cross(ray.dir, cd_min_co);
	abc[0] = ft_vec3d_dot(axis_xy[1], axis_xy[1]);
	abc[1] = 2 * ft_vec3d_dot(axis_xy[0], axis_xy[1]);
	abc[2] = ft_vec3d_dot(axis_xy[0], axis_xy[0]) - (cyl->radius * cyl->radius
		* ft_vec3d_dot(cd_min_co, cd_min_co));
	if (solve_quadratic(abc, hits) < 0 || hits[0] < 0)
		return (0);
	*t = hits[0];
	return (1);
}

t_vec3d			obj_cylinder_normal(t_cylinder *cyl, t_vec3d pt)
{
	double		pt_axis_off;
	t_vec3d		pt_orig_off;
	t_vec3d		axis_pt;

	pt_orig_off = ft_vec3d_sub(cyl->orig, pt);
	pt_axis_off = ft_vec3d_dot(pt_orig_off, pt_orig_off)
		- cyl->radius * cyl->radius;
	pt_axis_off = sqrt(pt_axis_off);
	if (ft_vec3d_dot(pt_orig_off, cyl->dir) > 0)
		pt_axis_off *= -1;
	axis_pt = ft_vec3d_add(cyl->orig, ft_vec3d_scale(cyl->dir, pt_axis_off));
	return (ft_vec3d_div_by(ft_vec3d_sub(pt, axis_pt), cyl->radius));
}
