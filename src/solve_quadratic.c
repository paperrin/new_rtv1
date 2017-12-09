/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:48:42 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/09 12:41:05 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		solve_quadratic(double *abc, double *values)
{
	double		discr;
	double		tmp;

	discr = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discr < 0)
		return (-1);
	discr = sqrt(discr);
	values[0] = (-abc[1] - discr) / (2 * abc[0]);
	values[1] = (-abc[1] + discr) / (2 * abc[0]);
	if (values[1] < values[0])
	{
		tmp = values[1];
		values[1] = values[0];
		values[0] = tmp;
	}
	return (discr);
}
