/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:18:26 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/16 17:02:11 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	int	tab[4];
	int	i;
	int	size_tab;

	tab[0] = 1;
	tab[1] = 742;
	tab[2] = 3444444;
	tab[3] = 7884;
	i = 0;
	size_tab = sizeof(tab) / 4;
	printf("size_tab = %d\n", size_tab);
	printf("before ft_rev_int_tab\n");
	while (i < size_tab)
		printf("%d\n", tab[i++]);
	printf("after ft_rev_int_tab\n");
	ft_rev_int_tab(tab, size_tab);
	i = 0;
	while (i < size_tab)
		printf("%d\n", tab[i++]);
	return (0);
}*/
