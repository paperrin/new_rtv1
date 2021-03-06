/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:12:23 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/09 12:37:02 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		obj_cylinder(t_vec3d orig, t_vec3d dir, double radius
		, t_clrf_rgb color)
{
	t_obj		obj;

	obj.type = obj_type_cylinder;
	obj.as.cylinder.orig = orig;
	obj.as.cylinder.dir = dir;
	obj.as.cylinder.radius = radius;
	obj.as.cylinder.color = color;
	return (obj);
}

int				obj_cylinder_ray_hit(t_cylinder *cyl, t_ray ray, double *t)
{
	t_vec3d		pdp;
	t_vec3d		eyexpdp;
	t_vec3d		rdxpdp;
	double		abc[3];
	double		hits[2];

	pdp = ft_vec3d_sub(ft_vec3d_sub(cyl->orig, cyl->dir), cyl->orig);
	eyexpdp = ft_vec3d_cross(ft_vec3d_sub(ray.orig, cyl->orig), pdp);
	rdxpdp = ft_vec3d_cross(ray.dir, pdp);
	abc[0] = ft_vec3d_dot(rdxpdp, rdxpdp);
	abc[1] = 2 * ft_vec3d_dot(rdxpdp, eyexpdp);
	abc[2] = ft_vec3d_dot(eyexpdp, eyexpdp) - (cyl->radius * cyl->radius
		* ft_vec3d_dot(pdp, pdp));
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
