/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:39 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/06 18:18:40 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());

int	ft_cmp(void *data, void *data_ref)
{
	int	nbr1;
	int	nbr2;

	nbr1 = *(int *)data;
	nbr2 = *(int *)data_ref;
	return (nbr1 - nbr2);
}

int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*current;
	t_list	*next;
	t_list	*result;
	int		nbr1;
	int		nbr2;
	int		nbr3;
	int		data;

	nbr1 = 44;
	nbr2 = 42;
	nbr3 = 41;
	data = 42;
	first = ft_create_elem(&nbr1);
	second = ft_create_elem(&nbr2);
	third = ft_create_elem(&nbr3);
	first->next = second;
	second->next = third;
	third->next = NULL;
	result = ft_list_find(first, &data, &ft_cmp);
	if (result)
	{
		printf("result = %d\n", *(int *)(result->data));
	}
	else
		printf("Data not found in list.\n");
	current = first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (0);
}
