/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:39 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/01 14:15:35 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);

int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*new_list;
	t_list	*current;
	t_list	*next;
	int		nbr1;
	int		nbr2;
	int		nbr3;
	int		data;

	nbr1 = 92;
	nbr2 = 102;
	nbr3 = 42;
	data = 452890;
	first = ft_create_elem(&nbr1);
	second = ft_create_elem(&nbr2);
	third = ft_create_elem(&nbr3);
	first->next = second;
	second->next = third;
	third->next = NULL;
	new_list = ft_create_elem(&data);
	ft_list_merge(&first, new_list);
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
