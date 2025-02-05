/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:42:36 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/16 14:50:08 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*#include <stdio.h>

int	main(void)
{
	int	nbr1;
	int	nbr2;
	int	div;
	int	mod;

	nbr1 = 42;
	nbr2 = 17;
	ft_div_mod(nbr1, nbr2, &div, &mod);
	printf("div = %d mod = %d\n", div, mod);
	return (0);
}*/
