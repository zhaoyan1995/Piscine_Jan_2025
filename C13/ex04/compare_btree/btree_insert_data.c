/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:27:17 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/13 23:00:28 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "stdlib.h"

/*void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	t_btree	*current;

	if (!*root || !root)
	{
		*root = btree_create_node(item);
		return ;
	}
	current = *root;
	if (cmpf((current->item), item) > 0)
	{
		if (current->left == NULL)
			current->left = btree_create_node(item);
		else
			btree_insert_data(&(current->left), item, cmpf);
	}
	else
	{
		if (current->right == NULL)
			current->right = btree_create_node(item);
		else
			btree_insert_data(&(current->right), item, cmpf);
	}
}*/

void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	if (!*root || !root)
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(((*root)->item), item) > 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
}
