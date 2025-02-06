/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:05:32 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/06 16:22:40 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*new_tab;
	int	i;

	new_tab = (int *)malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		new_tab[i] = f(tab[i]);
		i++;
	}
	return (new_tab);
}

int	ft_double(int nb)
{
	return (nb * 2);
}

int	main(void)
{
	int	tab[] = {1, 2, 3, 4};
	int	*new_tab;
	int	i;

	new_tab = ft_map(tab, 4, &ft_double);
	i = 0;
	while (new_tab[i])
	{
		printf("new_tab[%d] = %d\n", i, new_tab[i]);
		i++;
	}
	return (0);
}
