/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:30:11 by paperrin          #+#    #+#             */
/*   Updated: 2016/12/14 19:06:54 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strnjoin(t_strnjoin_arg s1, t_strnjoin_arg s2)
{
	char	*ret;

	if (!s1.s || !s2.s)
		return (NULL);
	s1.n = s1.n < 0 ? ft_strlen(*s1.s) : s1.n;
	s2.n = s2.n < 0 ? ft_strlen(*s2.s) : s2.n;
	ret = (char*)malloc(sizeof(char) * (s1.n + s2.n + 1));
	if (ret)
	{
		ret = ft_memcpy(ret, *s1.s, s1.n * sizeof(char));
		ft_memcpy(ret + (s1.n * sizeof(char)), *s2.s, s2.n * sizeof(char));
		ret[s1.n + s2.n] = '\0';
	}
	return (ret);
}

char	*ft_strnjoin_free(t_strnjoin_arg s1, t_strnjoin_arg s2, int free)
{
	char	*ret;

	ret = ft_strnjoin(s1, s2);
	if (!ret)
		return (NULL);
	if (free == STRJOIN_FREE_BOTH || free == STRJOIN_FREE_S1)
		ft_strdel(s1.s);
	if (free == STRJOIN_FREE_BOTH || free == STRJOIN_FREE_S2)
		ft_strdel(s2.s);
	return (ret);
}
