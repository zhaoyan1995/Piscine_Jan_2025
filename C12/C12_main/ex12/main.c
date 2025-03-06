/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:39 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/04 23:15:07 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>

t_list	*ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(), void (*free_fct)(void *));
void	free_fct(void *data);

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
	int		*nbr1;
	int		*nbr2;
	int		*nbr3;
	int		data;

	nbr1 = malloc(sizeof(int));
	if (nbr1 == NULL)
		return (1);
	nbr2 = malloc(sizeof(int));
	if (nbr2 == NULL)
		return (1);
	nbr3 = malloc(sizeof(int));
	if (nbr2 == NULL)
		return (1);
	*nbr1 = 2;
	*nbr2 = 102;
	*nbr3 = 42;
	data = 102;
	first = ft_create_elem(nbr1);
	second = ft_create_elem(nbr2);
	third = ft_create_elem(nbr3);
	first->next = second;
	second->next = third;
	third->next = NULL;
	ft_list_remove_if(&first, &data, &ft_cmp, &free_fct);
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
		free(current->data);
		free(current);
		current = next;
	}
	return (0);
}
