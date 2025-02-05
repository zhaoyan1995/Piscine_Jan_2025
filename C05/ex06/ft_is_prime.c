/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:20:13 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/24 00:55:33 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_helper_prime(int nb, int factor)
{
	int	nb_factor;

	nb_factor = 0;
	while (factor <= nb)
	{
		if (nb % factor == 0)
			nb_factor++;
		factor++;
	}
	return (nb_factor);
}

int	ft_is_prime(int nb)
{
	int	nb_factor;

	if (nb <= 1)
		return (0);
	nb_factor = ft_helper_prime(nb, 1);
	if (nb_factor > 2)
		return (0);
	else
		return (1);
}

/*#include <stdio.h>

int	main(void)
{
	printf("ft is %d\n",ft_is_prime(7));
	return (0);
}*/
