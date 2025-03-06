/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:39 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/04 23:11:21 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

void	free_fct(void *data)
{
	free(data);
}

int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*current;
	int		*nbr1;
	int		*nbr2;
	int		*nbr3;

	nbr1 = malloc(sizeof(int));
	*nbr1 = 45;
	if (!nbr1)
		return (1);
	nbr2 = malloc(sizeof(int));
	if (!nbr2)
		return (1);
	*nbr2 = 24;
	nbr3 = malloc(sizeof(int));
	if (!nbr3)
		return (1);
	*nbr3 = 35;
	first = ft_create_elem(nbr1);
	second = ft_create_elem(nbr2);
	third = ft_create_elem(nbr3);
	first->next = second;
	second->next = third;
	third->next = NULL;
	current = first;
	while (current)
	{
		if (current->data)
			printf("str = %d\n", *(int *)(current->data));
		current = current->next;
	}
	ft_list_clear(first, free_fct);
	return (0);
}
