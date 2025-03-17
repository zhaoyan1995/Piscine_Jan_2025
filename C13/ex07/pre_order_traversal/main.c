/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:52:09 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/15 18:58:50 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	free_btree(t_btree *root);
void	btree_apply_by_level(t_btree *root,
			void (*applyf)(void *item, int current_level, int is_first_elem));
void	applyf(void *item, int current_level, int is_first_elem);

int	main(void)
{
	t_btree	*a;

	a = btree_create_node("a");
	a->left = btree_create_node("b");
	a->right = btree_create_node("c");
	a->left->left = btree_create_node("d");
	a->right->left = btree_create_node("e");
	a->right->right = btree_create_node("f");
	a->right->right->right = btree_create_node("g");
	a->right->right->left = btree_create_node("h");
	a->left->left->right = btree_create_node("i");
	btree_apply_by_level(a, applyf);
	free_btree(a);
}
