/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:43:11 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/16 00:06:51 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int	count_node(t_btree *root)
{
	int	result_left;
	int	result_right;

	if (!root)
		return (0);
	result_left = count_node(root->left);
	result_right = count_node(root->right);
	return (result_left + result_right + 1);
}

void	fill_level_tab(t_btree *root, int current_level, int *level, int *index)
{
	if (!root)
		return ;
	level[*index] = current_level;
	(*index)++;
	fill_level_tab(root->left, current_level + 1, level, index);
	fill_level_tab(root->right, current_level + 1, level, index);
}

void	btree_apply_by_level2(t_btree *root, int *level, int *index,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	is_first_elem;
	int	i;

	if (!root)
		return ;
	i = 0;
	is_first_elem = 1;
	while (i < *index)
	{
		if (level[i] == level[*index])
		{
			is_first_elem = 0;
			break ;
		}
		i++;
	}
	applyf(root->item, level[*index], is_first_elem);
	(*index)++;
	btree_apply_by_level2(root->left, level, index, applyf);
	btree_apply_by_level2(root->right, level, index, applyf);
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int	nbr_node;
	int	*level;
	int	index;

	nbr_node = count_node(root);
	level = malloc(nbr_node * sizeof(int));
	if (level == NULL)
		return ;
	index = 0;
	fill_level_tab(root, 0, level, &index);
	index = 0;
	btree_apply_by_level2(root, level, &index, applyf);
	free(level);
}
