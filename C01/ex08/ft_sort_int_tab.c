/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:21:31 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/16 19:35:02 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tempo;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (i + j < size)
		{
			if (tab[i] > tab[i + j])
			{
				tempo = tab[i];
				tab[i] = tab[i + j];
				tab[i + j] = tempo;
			}
			j++;
		}
		i++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	int	tab[5];
	int	i;
	int	size_tab;

	tab[0] = 5;
	tab[1] = 4;
	tab[2] = 9;
	tab[3] = 2;
	tab[4] = 1;
	i = 0;
	size_tab = sizeof(tab) / 4;
	printf("before using ft_sort_int_tab function\n");		
	while (i < size_tab)
	{
		printf("i = %d tab[i] = %d\n", i, tab[i]);
		i++;
	}
	printf("after using ft_sort_int_tab function\n");
	ft_sort_int_tab(tab, size_tab);
	i = 0;
	while (i < size_tab)
	{
		
		
		printf("i = %d tab[i] = %d\n", i, tab[i]);
		i++;
	}
	return (0);
}*/
