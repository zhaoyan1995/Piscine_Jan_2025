/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:35:19 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/08 19:36:29 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>
#include <stdlib.h>

t_btree	*btree_create_node(void *item);
void	*free_btree(t_btree *root);

int	main(void)
{
	t_btree	*first;
	t_btree	*first_1;
	t_btree	*first_2;
	t_btree	*current;
	char	*str;
	char	*str_1;
	char	*str_2;

	str = "a";
	str_1 = "a left";
	str_2 = "a right";
	first = btree_create_node(str);
	first_1 = btree_create_node(str_1);
	first_2 = btree_create_node(str_2);
	first->left = first_1;
	first->right = first_2;
	current = first;
	while (current)
	{
		printf("current left = %s\n", (char *)(current->item));
		current = current->left;
	}
	current = first;
	while (current)
	{
		printf("current right = %s\n", (char *)(current->item));
		current = current->right;
	}
	free_btree(first);
	return (0);
}
