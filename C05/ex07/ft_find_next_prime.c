/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:57:58 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/24 01:28:09 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	factor;
	int	nb_factor;

	factor = 1;
	nb_factor = 0;
	while (factor <= nb)
	{
		if (nb % factor == 0)
			nb_factor++;
		factor++;
	}
	return (nb_factor);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		nb = 2;
	while (1)
	{
		if (ft_is_prime(nb) == 2)
			break ;
		else
			nb++;
	}
	return (nb);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_find_next_prime(81));
	return (0);
}*/
