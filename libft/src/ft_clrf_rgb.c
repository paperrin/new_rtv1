/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clrf_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:37:08 by paperrin          #+#    #+#             */
/*   Updated: 2017/11/28 00:49:56 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

t_clrf_rgb		ft_clrf_rgba(float r, float g, float b, float a)
{
	return ((t_clrf_rgb){r, g, b, a});
}

t_clrf_rgb		ft_clrf_rgb(float r, float g, float b)
{
	return ((t_clrf_rgb){r, g, b, 1});
}

t_clrf_rgb		ft_clrf_rgb_clamp(t_clrf_rgb color)
{
	color.r = MIN(color.r, 1);
	color.g = MIN(color.g, 1);
	color.b = MIN(color.b, 1);
	color.r = MAX(color.r, 0);
	color.g = MAX(color.g, 0);
	color.b = MAX(color.b, 0);
	return (color);
}

t_color_rgb		ft_clrf_rgb_to_rgb(t_clrf_rgb fcolor)
{
	return (ft_color_rgb(fcolor.r * 255, fcolor.g * 255, fcolor.b * 255));
}

unsigned int	ft_clrf_rgb_to_int(t_clrf_rgb fl_color, int endian)
{
	return (ft_color_rgb_to_int(ft_clrf_rgb_to_rgb(fl_color), endian));
}
