/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:39 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/01 23:20:22 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>

void	ft_list_sort(t_list **begin_list1, int (*cmp)());

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
	t_list	*next;
	int		nbr1;
	int		nbr2;
	int		nbr3;

	nbr1 = 92;
	nbr2 = 2;
	nbr3 = 42;
	first = ft_create_elem(&nbr1);
	second = ft_create_elem(&nbr2);
	third = ft_create_elem(&nbr3);
	first->next = second;
	second->next = third;
	third->next = NULL;
	ft_list_sort(&first, &ft_cmp);
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
