/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:50:28 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/13 23:21:43 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	ft_convert_to_char(void *data);
void	ft_putstr(char *str);

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_strcmp_void_data(void *data1, void *data2)
{
	return (ft_strcmp((char *)data1, (char *)data2));
}

int	main(void)
{
	t_btree	*d;

	d = btree_create_node("d");
	d->left = btree_create_node("b");
	d->right = btree_create_node("f");
	d->left->left = btree_create_node("a");
	d->left->right = btree_create_node("c");
	d->right->left = btree_create_node("e");
	d->right->right = btree_create_node("g");
	btree_apply_infix(d, ft_convert_to_char);
	free_btree(d);
	return (0);
}
