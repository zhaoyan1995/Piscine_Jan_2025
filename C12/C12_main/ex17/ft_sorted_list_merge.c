/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:57:03 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/07 00:14:30 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current_1;

	if (!begin_list2)
		return ;
	if (!begin_list1 || !*begin_list1)
		*begin_list1 = begin_list2;
	else
	{
		current_1 = *begin_list1;
		while (current_1->next)
			current_1 = current_1->next;
		current_1->next = begin_list2;
	}
}

int	len_linked_list(t_list **begin_list1)
{
	int		i;
	t_list	*current;

	i = 0;
	current = *begin_list1;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	ft_list_sort(t_list **begin_list1, int (*cmp)())
{
	int		len;
	int		i;
	void	*temp;
	t_list	*current;

	len = len_linked_list(begin_list1);
	current = *begin_list1;
	i = 0;
	while (i < len)
	{
		current = *begin_list1;
		while (current && current->next)
		{
			if (cmp(current->data, current->next->data) > 0)
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;
			}
			current = current->next;
		}
		i++;
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	ft_list_merge(begin_list1, begin_list2);
	ft_list_sort(begin_list1, cmp);
}
