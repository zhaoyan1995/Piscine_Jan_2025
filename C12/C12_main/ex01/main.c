/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:46:18 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/21 18:36:53 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_push_front(t_list **begin_list, void *data);

int	main(void)
{
	int		nbr1;
	int		nbr2;
	t_list	*begin_list;
	t_list	*current;

	nbr1 = 42;
	nbr2 = 3453;
	begin_list = NULL;
	ft_list_push_front(&begin_list, &nbr1);
	ft_list_push_front(&begin_list, &nbr2);
	current = begin_list;
	while (current)
	{
		printf("%d\n", *(int *)((current)->data));
		current = (current)->next;
	}
	return (0);
}
