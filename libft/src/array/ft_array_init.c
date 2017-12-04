/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:37:34 by paperrin          #+#    #+#             */
/*   Updated: 2017/11/10 22:56:40 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_array				ft_array_init(void (*f_free)(void**))
{
	t_array		array;

	array = (t_array){
		.data = NULL,
		.begin = NULL,
		.end = NULL,
		.f_free = f_free,
		.size = 0,
		.reserve_front = 0,
		.reserve_back = 0
	};
	return (array);
}
