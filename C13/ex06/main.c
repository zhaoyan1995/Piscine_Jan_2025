/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:35:19 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/12 15:38:31 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		btree_level_count(t_btree *root);
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

int	ft_strcmp(void *data1, void *data2)
{
	char	*s1;
	char	*s2;

	s1 = (char *)data1;
	s2 = (char *)data2;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(void)
{
	t_btree	*a;
	t_btree	*b;
	t_btree	*c;
	t_btree	*d;
	t_btree	*e;
	t_btree	*f;
	t_btree	*g;
	int		result;
	int		nbr_a;
	int		nbr_b;
	int		nbr_c;
	int		nbr_d;
	int		nbr_e;
	int		nbr_f;
	int		nbr_g;

	nbr_a = 7;
	nbr_b = 2;
	nbr_c = 3;
	nbr_d = 4;
	nbr_e = 5;
	nbr_f = 9;
	nbr_g = 42;
	a = btree_create_node(&nbr_a);
	b = btree_create_node(&nbr_b);
	c = btree_create_node(&nbr_c);
	d = btree_create_node(&nbr_d);
	e = btree_create_node(&nbr_e);
	f = btree_create_node(&nbr_f);
	g = btree_create_node(&nbr_g);
	a->left = b;
	a->right = c;
	b->left = d;
	c->left = e;
	c->right = f;
	f->left = g;
	result = btree_level_count(a);
	if (result)
		printf("result = %d\n", result);
	else
		printf("not found\n");
	free_btree(a);
	return (0);
}
