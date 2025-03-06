/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:46:18 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/22 19:49:21 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_list_last(t_list *begin_list);

int	main(void)
{
	int		nbr1;
	int		nbr2;
	int		nbr3;
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*current;
	t_list	*next;
	t_list	*result;

	nbr1 = 42;
	nbr2 = 3453;
	nbr3 = 456;
	first = ft_create_elem(&nbr1);
	if (first == NULL)
		return (1);
	second = ft_create_elem(&nbr2);
	if (second == NULL)
	{
		free(first);
		return (1);
	}
	third = ft_create_elem(&nbr3);
	if (third == NULL)
	{
		free(first);
		free(second);
		return (1);
	}
	first->next = second;
	second->next = third;
	third->next = NULL;
	current = first;
	while (current)
	{
		printf("%d\n", *(int *)(current->data));
		current = (current)->next;
	}
	result = ft_list_last(first);
	printf("the last one is %d\n", *(int *)(result->data));
	current = first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (0);
}
