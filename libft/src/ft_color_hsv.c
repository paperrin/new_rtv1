/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_hsv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 19:53:52 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/07 22:24:06 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

t_color_hsv		ft_color_hsv(unsigned short h, unsigned char s
		, unsigned char v)
{
	return ((t_color_hsv){h % 360, s % 100, v % 100});
}
