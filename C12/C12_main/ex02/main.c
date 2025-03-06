/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:11:57 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/06 17:47:41 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_list_size(t_list *begin_list);

int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*current;
	t_list	*current2;
	t_list	*next;
	int		nbr1;
	int		nbr2;
	int		nbr3;

	nbr1 = 34;
	nbr2 = 41;
	nbr3 = 90;
	first = ft_create_elem(&nbr1);
	second = ft_create_elem(&nbr2);
	third = ft_create_elem(&nbr3);
	first->next = second;
	second->next = third;
	third->next = NULL;
	current = first;
	printf("size of linked list = %d\n", ft_list_size(current));
	while (current)
	{
		printf("%d\n", *(int *)(current->data));
		current = current->next;
	}
	current2 = first;
	while (current2)
	{
		next = current2->next;
		free(current2);
		current2 = next;
	}
	return (0);
}
