/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:52:31 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/23 22:17:32 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_helper(int nb, int result)
{
	if (result == nb)
		return (0);
	if (nb != result * result)
		return (ft_sqrt_helper(nb, result + 1));
	else
		return (result);
}

int	ft_sqrt(int nb)
{
	if (nb <= 0)
		return (0);
	else if (nb == 1)
		return (1);
	return (ft_sqrt_helper(nb, 1));
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_sqrt(-15));
	return (0);
}*/
