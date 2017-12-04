/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_ft_vector.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 22:19:59 by paperrin          #+#    #+#             */
/*   Updated: 2017/12/01 22:20:41 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_FT_VECTOR_H
# define INTERNAL_FT_VECTOR_H

# include "ft_vector.h"

/*
** vector/internal_ft_vector_range.c
*/
int				internal_ft_vector_copy_range(t_vector *vector, char *dst
		, char *src, size_t n);
void			internal_ft_vector_free_range(t_vector *vector, char *data
		, size_t n);
char			*internal_ft_vector_perase_n_should_free(t_vector *vector,
		char *elem_first, size_t n, int should_free);

#endif
