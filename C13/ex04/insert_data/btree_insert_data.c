/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:27:17 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/14 14:32:45 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include "stdlib.h"

//Solution No.1
/*void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *))
{
	t_btree	*current;

	if (!*root || !root)
	{
		*root = btree_create_node(item); //when the root == NULL at the beginning, we insert the item for the first node of root
		return ; //stop the recursivite
	}
	current = *root;
	if (cmpf((current->item), item) > 0)
	{
		if (current->left == NULL)  //Here we check that if we need to continue the recursivity or not
			current->left = btree_create_node(item); //if == NULL then we create a new node with item and then STOP the recursivity process
		else   //Else if current->left != NULL, then we continue the recursivity process (we don't use if return to stop the recursivity in this case
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

//Solution No.2

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
