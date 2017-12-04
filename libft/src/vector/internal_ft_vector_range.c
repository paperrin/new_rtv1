/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_ft_vector_range.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 23:05:58 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/02 17:14:02 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

int				internal_ft_vector_copy_range(t_vector *vector, char *dst
		, char *src, size_t n)
{
	char	*dst_copy;
	size_t	i;

	if (!vector->f_copy)
		ft_memmove(dst, src, n * vector->data_size);
	else
	{
		dst_copy = dst;
		i = 0;
		while (i < n)
		{
			if (!(*vector->f_copy)(dst, src))
				break ;
			dst += vector->data_size;
			src += vector->data_size;
			i++;
		}
		if (i != n)
			return (0);
	}
	return (1);
}

void			internal_ft_vector_free_range(t_vector *vector, char *data
		, size_t n)
{
	if (!vector->f_free)
		return ;
	while (n--)
	{
		(*vector->f_free)(data);
		data += vector->data_size;
	}
}

char			*internal_ft_vector_perase_n_should_free(t_vector *vector,
		char *elem_first, size_t n, int should_free)
{
	size_t		vector_size;
	size_t		elem_first_index;

	vector_size = ft_vector_size(vector);
	if (elem_first < vector->begin || elem_first > vector->end || n < 1)
		return (elem_first);
	elem_first_index = (elem_first - vector->begin) / vector->data_size;
	n = MIN(n, vector_size - elem_first_index);
	if (should_free)
		internal_ft_vector_free_range(vector, elem_first, n);
	if (elem_first_index + n < vector_size)
	{
		if (!internal_ft_vector_copy_range(vector, elem_first,
				&vector->begin[elem_first_index + n],
				vector_size - (elem_first_index + n)))
			return (NULL);
	}
	vector->end -= vector->data_size * n;
	vector->reserve += n;
	return (elem_first);
}
