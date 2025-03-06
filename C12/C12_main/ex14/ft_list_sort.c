/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:56:08 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/01 23:50:04 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	count_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	ft_swap(void **data1, void **data2)
{
	void	*tempo;

	tempo = *data1;
	*data1 = *data2;
	*data2 = tempo;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	int		size;
	int		i;

	if (!begin_list || !*begin_list)
		return ;
	size = count_size(*begin_list);
	i = 0;
	while (i < size - 1)
	{
		current = *begin_list;
		while (current->next)
		{
			if (cmp(current->data, current->next->data) > 0)
				ft_swap(&(current->data), &(current->next->data));
			current = current->next;
		}
		i++;
	}
}
