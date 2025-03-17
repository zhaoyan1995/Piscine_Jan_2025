/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:43:11 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/17 17:48:37 by ZHAOYAN          ###   ########.fr       */
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

void	put_into_queue(t_queue *array)
{
	t_btree	*current_node;

	if (array->rear >= array->max_size)
		return ;
	current_node = array->node[array->front];
	if (current_node->left)
	{
		array->node[array->rear++] = current_node->left;
		array->nbr_next_level++;
	}
	if (current_node->right)
	{
		array->node[array->rear++] = current_node->right;
		array->nbr_next_level++;
	}
}

void	btree_apply_by_level2(t_queue *array,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int		current_level;
	int		is_first_elem;

	current_level = 0;
	array->nbr_current_level = 1;
	array->nbr_next_level = 0;
	is_first_elem = 1;
	while (array->front < array->rear)
	{
		put_into_queue(array);
		applyf(array->node[array->front]->item, current_level, is_first_elem);
		array->front++;
		is_first_elem = 0;
		array->nbr_current_level--;
		if (array->nbr_current_level == 0)
		{
			array->nbr_current_level = array->nbr_next_level;
			array->nbr_next_level = 0;
			current_level++;
			is_first_elem = 1;
		}
	}
}

void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_queue	*array;

	if (!root || !applyf)
		return ;
	array = malloc(sizeof(t_queue));
	if (!array)
		return ;
	array->max_size = count_node(root);
	array->node = malloc(sizeof(t_btree *) * array->max_size);
	if (!array->node)
	{
		free(array);
		return ;
	}
	array->front = 0;
	array->rear = 0;
	array->node[array->rear++] = root;
	btree_apply_by_level2(array, applyf);
	free(array->node);
	free(array);
}
