/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:15:05 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/23 13:12:34 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

/*CAUTION : Current should not be equal to NULL int this function
 * Otherwise, there will be segmentation fault in the commande line.
 * begin list should not be moved, so we create a new variable current
 * in order to check the last element in begin_list and add a new_list
 * at the end of the begin_list*/

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_list;
	t_list	*current;

	new_list = ft_create_elem(data);
	if (!new_list)
		return ;
	if (!*begin_list)
	{
		*begin_list = new_list;
		return ;
	}
	current = *begin_list;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_list;
}
