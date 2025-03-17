/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:35:19 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/11 22:41:19 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_btree	*btree_create_node(void *item);
void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *));
void	free_btree(t_btree *root);

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

int	cmp(void *data1, void *data2)
{
	int	nbr1;
	int	nbr2;

	nbr1 = *(int *)data1;
	nbr2 = *(int *)data2;
	return (nbr1 - nbr2);
}

int	main(int argc, char **argv)
{
	t_btree	*a;
	t_btree	*b;
	t_btree	*c;
	t_btree	*d;
	t_btree	*e;
	t_btree	*f;
	void	*result;
	int		nbr_a;
	int		nbr_b;
	int		nbr_c;
	int		nbr_d;
	int		nbr_e;
	int		nbr_f;
	int		new;

	if (argc == 2)
	{
		nbr_a = 7;
		nbr_b = 2;
		nbr_c = 3;
		nbr_d = 4;
		nbr_e = 5;
		nbr_f = 9;
		new = atoi(argv[1]);
		a = btree_create_node(&nbr_a);
		b = btree_create_node(&nbr_b);
		c = btree_create_node(&nbr_c);
		d = btree_create_node(&nbr_d);
		e = btree_create_node(&nbr_e);
		f = btree_create_node(&nbr_f);
		a->left = b;
		a->right = c;
		b->left = d;
		b->right = e;
		c->right = f;
		result = btree_search_item(a, &new, cmp);
		if (result)
			printf("result = %d\n", *(int *)(result));
		else
			printf("not found\n");
		free_btree(a);
	}
	return (0);
}
