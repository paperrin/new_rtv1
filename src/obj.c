/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 22:28:16 by paperrin          #+#    #+#             */
/*   Updated: 2017/11/30 18:09:21 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj		*obj_new(t_obj_type type, void *o)
{
	t_obj		*obj;

	if (!o || !(obj = (t_obj*)malloc(sizeof(*obj))))
	{
		if (o)
			free(o);
		return (NULL);
	}
	obj->type = type;
	obj->o = o;
	return (obj);
}

void		obj_free(void **ptr)
{
	t_obj	**obj;

	obj = (t_obj**)ptr;
	if (*obj)
	{
		if ((*obj)->o)
			free((*obj)->o);
		ft_memdel(ptr);
	}
}
