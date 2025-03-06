/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:22:56 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/04 15:34:13 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

//if the new_list is not the smallest one, 
//then we use this function to insert it in the middle 
//or the end of the linked lists.
void	ft_sorted_list_insert2(t_list **begin_list, t_list *new_list,
	int (*cmp)())
{
	t_list	*current;
	t_list	*prev;

	current = *begin_list;
	prev = 0;
	while (current)
	{
		if (cmp(current->data, new_list->data) > 0)
		{
			prev->next = new_list;
			new_list->next = current;
			return ;
		}
		prev = current;
		current = current->next;
	}
	prev->next = new_list;
}

//if the new_list is the smallest one, 
//we insert it at the beginning of the linked lists.
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*new_list;

	if (!data)
		return ;
	new_list = ft_create_elem(data);
	if (!new_list)
		return ;
	if (!*begin_list)
	{
		*begin_list = new_list;
		return ;
	}
	current = *begin_list;
	if (cmp(current->data, data) > 0)
	{
		new_list->next = current;
		*begin_list = new_list;
	}
	else
		ft_sorted_list_insert2(begin_list, new_list, cmp);
}
