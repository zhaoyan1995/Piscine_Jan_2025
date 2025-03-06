/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:39 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/23 18:12:46 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs);

int	main(void)
{
	char	*strs[4];
	int		size;
	t_list	*list;
	t_list	*current;
	t_list	*next;

	strs[0] = "hello";
	strs[1] = "lilou";
	strs[2] = "comment";
	strs[3] = NULL;
	size = sizeof(strs) / sizeof(*strs);
	list = ft_list_push_strs(size, strs);
	current = list;
	while (current)
	{
		if (current->data)
			printf("str = %s\n", (char *)(current->data));
		current = current->next;
	}
	current = list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (0);
}
