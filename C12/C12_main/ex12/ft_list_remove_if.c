/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:57:42 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/01 01:23:47 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	free_fct(void *data)
{
	free(data);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	current = *begin_list;
	prev = NULL;
	while (current)
	{
		next = current->next;
		if (cmp(current->data, data_ref) == 0)
		{
			if (prev != NULL)
				prev->next = next;
			else
				*begin_list = next;
			free_fct(current->data);
			free(current);
		}
		else
			prev = current;
		current = next;
	}
}
