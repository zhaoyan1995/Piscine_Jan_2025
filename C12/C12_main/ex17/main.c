/* ************************************************************************** */
/*
              */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:39 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/02 01:17:21 by ZHAOYAN          ###   ########.fr       */
/*
              */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)());

int	ft_cmp(void *data1, void *data2)
{
	int	nbr1;
	int	nbr2;

	nbr1 = *(int *)data1;
	nbr2 = *(int *)data2;
	return (nbr1 - nbr2);
}

int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*current;
	t_list	*one;
	t_list	*two;
	t_list	*three;
	t_list	*four;
	t_list	*next;
	int		nbr1;
	int		nbr2;
	int		nbr3;
	int		new_data1;
	int		new_data2;
	int		new_data3;
	int		new_data4;

	nbr1 = 17;
	nbr2 = 20;
	nbr3 = 143;
	new_data1 = 1;
	new_data2 = 12;
	new_data3 = 39;
	new_data4 = 119;
	first = ft_create_elem(&nbr1);
	second = ft_create_elem(&nbr2);
	third = ft_create_elem(&nbr3);
	first->next = second;
	second->next = third;
	third->next = NULL;
	one = ft_create_elem(&new_data1);
	two = ft_create_elem(&new_data2);
	three = ft_create_elem(&new_data3);
	four = ft_create_elem(&new_data4);
	one->next = two;
	two->next = three;
	three->next = four;
	ft_sorted_list_merge(&first, one, &ft_cmp);
	current = first;
	while (current)
	{
		printf("result = %d\n", *(int *)(current->data));
		current = current->next;
	}
	current = first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (0);
}
