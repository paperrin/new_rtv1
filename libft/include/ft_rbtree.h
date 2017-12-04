/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:42:06 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/28 17:01:01 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RBTREE_H
# define FT_RBTREE_H

# include <string.h>
# include <stdlib.h>
# include "libft.h"

# define RBTREE_COLOR_NULL			L"\e[35m"
# define RBTREE_COLOR_BRANCH		L"\e[30m"
# define RBTREE_COLOR_NODE_RED 		L"\e[37m\e[41m"
# define RBTREE_COLOR_NODE_BLACK	L"\e[37m\e[40m"
# define RBTREE_COLOR_NODE_RESET	L"\e[47m"
# define RBTREE_COLOR_GLOBAL_BASE	L"\e[47m\e[30m"
# define RBTREE_COLOR_GLOBAL_RESET	L"\e[0m"
# define RBTREE_BRANCH_VERTICAL		L'│'
# define RBTREE_BRANCH_CROSS		L'├'
# define RBTREE_BRANCH_CORNER		L'└'
# define RBTREE_BRANCH_HORIZONTAL	L'─'
# define RBTREE_BRANCH_SPACE		L' '
# define RBTREE_BRANCH_WIDTH		3
# define RBTREE_BRANCH_HEIGHT_PRE	0
# define RBTREE_BRANCH_HEIGHT_POST	1

typedef enum		e_rbtree_branch
{
	branch_space = 0,
	branch_vertical = 1,
	branch_cross = 2,
	branch_corner = 3
}					t_rbtree_branch;

typedef enum		e_rbtree_color
{
	rbtree_color_black,
	rbtree_color_red
}					t_rbtree_color;

typedef struct s_rbtree_node	t_rbtree_node;
struct				s_rbtree_node
{
	t_rbtree_color	color;
	t_rbtree_node	*parent;
	t_rbtree_node	*lchild;
	t_rbtree_node	*rchild;
	void			*content;
	size_t			content_size;
};

typedef struct		s_rbtree
{
	t_rbtree_node	*root;
	int				(*cmp_f)(void*, void*);
}					t_rbtree;

t_rbtree			ft_rbtree_new(int (*cmp_f)(void*, void*));
t_rbtree_node		*ft_rbtree_add(t_rbtree *tree, void *content
		, size_t content_size);
void				ft_rbtree_print(t_rbtree *tree
		, void (*to_string)(void *data));

#endif
