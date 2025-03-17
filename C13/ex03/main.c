/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:35:19 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/09 14:37:31 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>

t_btree	*btree_create_node(void *item);
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	free_btree(t_btree *root);

void	ft_putstr(void *str)
{
	char	*string;
	char	c;

	string = (char *)str;
	while (*string)
	{
		c = *string;
		write(1, &c, 1);
		string++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	t_btree	*a;
	t_btree	*b;
	t_btree	*c;
	t_btree	*d;
	t_btree	*e;
	char	*str_a;
	char	*str_b;
	char	*str_c;
	char	*str_d;
	char	*str_e;

	str_a = "A";
	str_b = "B (A->left)";
	str_c = "C (A->right)";
	str_d = "D (B->left)";
	str_e = "E (B->right)";
	a = btree_create_node(str_a);
	b = btree_create_node(str_b);
	c = btree_create_node(str_c);
	d = btree_create_node(str_d);
	e = btree_create_node(str_e);
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	btree_apply_suffix(a, ft_putstr);
	free_btree(a);
	return (0);
}
