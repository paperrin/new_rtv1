/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:55:23 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/11 15:26:52 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

void				ft_array_free(t_array *array)
{
	if (array->data)
		free(array->data);
	*array = (t_array){
		.data = NULL,
		.begin = NULL,
		.end = NULL,
		.f_free = NULL,
		.size = 0,
		.reserve_front = 0,
		.reserve_back = 0
	};
}
