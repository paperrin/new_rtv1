/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:58:17 by paperrin          #+#    #+#             */
/*   Updated: 2016/11/28 14:32:48 by paperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rbtree.h"

static wchar_t		*make_branch(t_rbtree_branch type)
{
	static const wchar_t	branch_types[4][2] = {
		{RBTREE_BRANCH_SPACE, RBTREE_BRANCH_SPACE},
		{RBTREE_BRANCH_VERTICAL, RBTREE_BRANCH_SPACE},
		{RBTREE_BRANCH_CROSS, RBTREE_BRANCH_HORIZONTAL},
		{RBTREE_BRANCH_CORNER, RBTREE_BRANCH_HORIZONTAL}
	};
	wchar_t					*branch;
	int						i;

	i = RBTREE_BRANCH_WIDTH + 2;
	branch = (wchar_t*)malloc(sizeof(wchar_t) * (i + 1));
	if (!branch)
		return (NULL);
	branch[i--] = '\0';
	while (i > 1)
		branch[i--] = branch_types[type][1];
	branch[i] = branch_types[type][0];
	branch[0] = RBTREE_BRANCH_SPACE;
	return (branch);
}

static void			print_branch(size_t n, t_rbtree_branch type
		, wchar_t *prefix, int el)
{
	wchar_t		*branch;

	if (n < 1)
		return ;
	if ((branch = make_branch(type)))
	{
		while (n--)
		{
			if (prefix)
				ft_putwstr(prefix);
			ft_putwstr(branch);
			if (el)
				ft_putendl("");
		}
		free(branch);
	}
}

static void			print_node(t_rbtree_node *node
		, void (*f_put)(void *content))
{
	if (node && node->color == rbtree_color_red)
		ft_putwstr(RBTREE_COLOR_NODE_RED);
	else
		ft_putwstr(RBTREE_COLOR_NODE_BLACK);
	ft_putwchar(RBTREE_BRANCH_SPACE);
	if (node && node->content)
		(*f_put)(node->content);
	else
		ft_putwstr("" RBTREE_COLOR_NULL L"{null}");
	ft_putwchar(RBTREE_BRANCH_SPACE);
	ft_putwstr("" RBTREE_COLOR_NODE_RESET RBTREE_COLOR_BRANCH);
	ft_putendl("");
}

static void			print_subtree(t_rbtree_node *node
		, wchar_t *prefix, int is_tail, void (*f_put)(void *content))
{
	wchar_t		*concat_prefix_l;
	wchar_t		*concat_prefix_r;
	wchar_t		*tmp;

	ft_putwstr(prefix);
	print_branch(1, is_tail ? branch_corner : branch_cross, NULL, 0);
	print_node(node, f_put);
	if (node)
	{
		tmp = make_branch(is_tail ? branch_space : branch_vertical);
		concat_prefix_l = ft_wstrjoin_free(&prefix, &tmp, 2);
		concat_prefix_r = ft_wstrdup(concat_prefix_l);
		if (node->lchild || node->rchild)
		{
			print_branch(RBTREE_BRANCH_HEIGHT_PRE, branch_vertical
					, concat_prefix_l, 1);
			print_subtree(node->rchild, concat_prefix_r, 0, f_put);
			print_branch(RBTREE_BRANCH_HEIGHT_POST, branch_vertical
					, concat_prefix_l, 1);
			print_subtree(node->lchild, concat_prefix_l, 1, f_put);
		}
	}
}

void				ft_rbtree_print(t_rbtree *tree
		, void (*f_put)(void *content))
{
	wchar_t		*prefix;

	ft_putwstr("" RBTREE_COLOR_GLOBAL_BASE RBTREE_COLOR_BRANCH L"\n\n");
	prefix = ft_wstrdup(L"");
	print_subtree(tree->root, prefix, 1, f_put);
	ft_putwstr("" RBTREE_COLOR_GLOBAL_RESET);
	ft_putendl("\n");
}
