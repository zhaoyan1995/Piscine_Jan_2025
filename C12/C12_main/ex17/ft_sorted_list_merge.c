/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:57:03 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/06 15:57:52 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

void	ft_prev_helper(t_list **begin_list1, t_list *prev_1, t_list *current_2)
{
	if (prev_1)
		prev_1->next = current_2;
	else
		*begin_list1 = current_2;
}

void	ft_sorted_list_merge2(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	t_list	*prev_1;
	t_list	*current_1;
	t_list	*current_2;

	prev_1 = NULL;
	current_1 = *begin_list1;
	while (current_1 && begin_list2)
	{
		if (cmp(current_1->data, begin_list2->data) > 0)
		{
			current_2 = begin_list2;
			begin_list2 = begin_list2->next;
			ft_prev_helper(begin_list1, prev_1, current_2);
			current_2->next = current_1;
			prev_1 = current_2;
		}
		else
		{
			prev_1 = current_1;
			current_1 = current_1->next;
		}
	}
	if (begin_list2 && prev_1)
		prev_1->next = begin_list2;
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
			int (*cmp)())
{
	if (!begin_list2)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	ft_sorted_list_merge2(begin_list1, begin_list2, cmp);
}
