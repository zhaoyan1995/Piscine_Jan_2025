/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:43:59 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/16 15:50:08 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*#include <stdio.h>

int	main(void)
{
	int	nbr1;
	int	nbr2;

	nbr1 = 42;
	nbr2 = 17;
	ft_ultimate_div_mod(&nbr1, &nbr2);
	printf("div = %d, mod = %d", nbr1, nbr2);
	return (0);
}*/
