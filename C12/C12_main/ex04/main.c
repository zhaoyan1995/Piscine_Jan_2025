/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:39 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/23 13:19:49 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_push_back(t_list **begin_list, void *data);

int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*current;
	t_list	*next;
	int		nbr1;
	int		nbr2;
	int		nbr3;

	nbr1 = 4;
	nbr2 = 45;
	nbr3 = 37;
	first = ft_create_elem(&nbr3);
	second = ft_create_elem(&nbr2);
	first->next = second;
	second->next = NULL;
	if (!first)
		return (1);
	if (!second)
	{
		free(first);
		return (1);
	}
	ft_list_push_back(&first, &nbr1);
	current = first;
	while (current)
	{
		printf("nbr = %d\n", *(int *)(current->data));
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
