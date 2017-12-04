/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:48:02 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/26 16:38:12 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"

t_rbtree			ft_rbtree_new(int (*cmp_f)(void*, void*))
{
	t_rbtree	tree;

	tree.cmp_f = cmp_f;
	tree.root = NULL;
	return (tree);
}
