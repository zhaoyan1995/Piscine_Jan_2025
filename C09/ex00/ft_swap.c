/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:28:34 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/16 14:41:28 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	n;

	n = *a;
	*a = *b;
	*b = n;
}

/*#include <stdio.h>

int	main(void)
{
	int	nbr1;
	int	nbr2;

	nbr1 = 21;
	nbr2 = 42;
	printf("before ft_swap nbr1 = %d nbr2 = %d\n", nbr1, nbr2);
	ft_swap(&nbr1, &nbr2);
	printf("after ft_swap nbr1 = %d nbr2 = %d\n", nbr1, nbr2);
	return (0);
}*/
