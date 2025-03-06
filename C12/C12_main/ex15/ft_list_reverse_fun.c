/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 00:36:18 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/02 01:31:56 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*current;
	t_list	*next;
	t_list	*prev;

	if (!begin_list)
		return ;
	current = begin_list;
	prev = 0;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
}
