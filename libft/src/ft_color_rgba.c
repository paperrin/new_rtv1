/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_rgba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <paperrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 07:06:19 by paperrin          #+#    #+#             */
/*   Updated: 2017/10/11 14:34:03 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

t_color_rgba		ft_color_rgba(unsigned char r, unsigned char g
		, unsigned char b, float a)
{
	if (a > 1)
		a = 1;
	else if (a < 0)
		a = 0;
	return ((t_color_rgba){r, g, b, a});
}

t_color_rgb			ft_color_rgba_to_rgb(t_color_rgba rgba)
{
	return (ft_color_rgb(rgba.r, rgba.g, rgba.b));
}
