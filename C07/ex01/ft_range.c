/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:19:46 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/24 12:36:16 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*tab;
	int	i;
	int	nbr;

	if (min >= max)
		return (NULL);
	size = max - min;
	tab = (int *)malloc(size * sizeof(int));
	if (tab == NULL)
		return (NULL);
	i = 0;
	nbr = min;
	while (i < size)
	{
		tab[i] = nbr;
		i++;
		nbr++;
	}
	return (tab);
}

/*#include <stdio.h>

int	main(void)
{
	int	min;
	int	max;
	int	*tab;
	int	i;

	min = 3;
	max = 6;
	tab = ft_range(min, max);
	i = 0;	
	while (tab[i])
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	free(tab);
	return (0);
}*/
