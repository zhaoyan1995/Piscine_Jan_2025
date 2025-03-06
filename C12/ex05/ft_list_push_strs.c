/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:15:05 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/23 17:59:12 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list;
	t_list	*current;
	int		i;

	if (size <= 0)
		return (0);
	i = 0;
	list = ft_create_elem(strs[i]);
	i++;
	while (i < size)
	{
		current = ft_create_elem(strs[i]);
		current->next = list;
		list = current;
		i++;
	}
	return (list);
}
