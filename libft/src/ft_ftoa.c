/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:15:21 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/05 19:19:22 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>
#include <stdlib.h>

static char		*combine_nb(long i_part, long d_part, char *sep)
{
	char	*str;
	char	*i_str;
	char	*d_str;

	if (!(str = ft_itoa(i_part)))
		return (NULL);
	if (d_part > 0 && (i_str = ft_strjoin(str, sep)))
	{
		free(str);
		if (!(d_str = ft_itoa(d_part)))
		{
			free(i_str);
			return (NULL);
		}
		if (!(str = ft_strjoin(i_str, d_str)))
		{
			free(i_str);
			free(d_str);
		}
	}
	return (str);
}

char			*ft_ftoa(long double nb, unsigned int n_decimal, char *sep)
{
	char			*str;
	long			i_part;
	long			d_part;
	unsigned int	mult;

	i_part = (long)nb;
	d_part = -1;
	if (n_decimal > 0)
	{
		if (n_decimal > 9)
			n_decimal = 9;
		mult = pow(10, n_decimal);
		d_part = ABS((long)(nb * mult) % mult);
	}
	str = combine_nb(i_part, d_part, sep);
	return (str);
}
