/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:50:28 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/13 23:08:09 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

void	btree_insert_data(t_btree **root, void *item,
			int (*cmpf)(void *, void *));
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
	t_btree	*root;

	root = NULL;
	btree_insert_data(&root, "d", ft_strcmp_void_data);
	btree_insert_data(&root, "b", ft_strcmp_void_data);
	btree_insert_data(&root, "f", ft_strcmp_void_data);
	btree_insert_data(&root, "a", ft_strcmp_void_data);
	btree_insert_data(&root, "c", ft_strcmp_void_data);
	btree_insert_data(&root, "e", ft_strcmp_void_data);
	btree_insert_data(&root, "g", ft_strcmp_void_data);
	btree_apply_infix(root, ft_convert_to_char);
	free_btree(root);
	return (0);
}
