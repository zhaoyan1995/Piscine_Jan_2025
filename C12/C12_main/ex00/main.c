/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:39 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/20 18:42:12 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

t_list	*ft_create_elem(void *data);

int	main(void)
{
	t_list	*list;
	int		nbr;

	nbr = 4;
	list = ft_create_elem(&nbr);
	while (list)
	{
		printf("nbr = %d\n", *(int *)(list->data));
		list = list->next;
	}
	free(list);
	return (0);
}
