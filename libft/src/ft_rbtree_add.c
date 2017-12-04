/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:57:42 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/26 16:38:03 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"

static void		insert_node(t_rbtree_node **node, t_rbtree_node *new_node
		, int (*cmp_f)(void*, void*))
{
	if (!*node)
		*node = new_node;
	else
	{
		new_node->parent = *node;
		if ((*cmp_f)(new_node->content, (*node)->content) < 0)
			insert_node((&(*node)->lchild), new_node, cmp_f);
		else
			insert_node((&(*node)->rchild), new_node, cmp_f);
	}
}

t_rbtree_node	*ft_rbtree_add(t_rbtree *tree
		, void *content, size_t content_size)
{
	t_rbtree_node	*new_node;

	new_node = (t_rbtree_node*)malloc(sizeof(t_rbtree_node));
	if (!new_node)
		return (NULL);
	new_node->color = rbtree_color_red;
	new_node->parent = NULL;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	new_node->content = content;
	new_node->content_size = content_size;
	if (!content)
		content_size = 0;
	insert_node((&tree->root), new_node, tree->cmp_f);
	return (new_node);
}
