/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 18:14:24 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/05 17:01:09 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "my_unistd.h"

void	ft_putnchar(char c, size_t n)
{
	while (n-- > 0)
		write(1, &c, 1);
}
