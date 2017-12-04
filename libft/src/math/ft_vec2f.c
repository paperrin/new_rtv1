/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec2f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:45:13 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/29 19:42:47 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdlib.h>

t_vec2f			ft_vec2f(float x, float y)
{
	t_vec2f		ret;

	ret = (t_vec2f){
		.x = x,
		.y = y
	};
	return (ret);
}

t_vec2f			*ft_vec2f_new(float x, float y)
{
	t_vec2f		*ret;

	ret = (t_vec2f*)malloc(sizeof(t_vec2f));
	if (ret)
		*ret = ft_vec2f(x, y);
	return (ret);
}
