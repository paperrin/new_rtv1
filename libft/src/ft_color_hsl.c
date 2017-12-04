/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_hsl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 20:00:57 by paperrin          #+#    #+#             */
/*   Updated: 2017/08/07 22:24:46 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

t_color_hsl		ft_color_hsl(unsigned short h, unsigned char s
		, unsigned char l)
{
	return ((t_color_hsl){h % 360, s % 100, l % 100});
}
