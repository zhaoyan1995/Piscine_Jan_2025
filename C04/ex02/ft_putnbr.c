/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:28:55 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/22 19:43:32 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			ft_putnbr(-(nb / 10));
			write(1, "8", 1);
		}
		else
			ft_putnbr(-nb);
	}
	else
	{
		if (nb / 10 > 0)
			ft_putnbr(nb / 10);
		digit = nb % 10 + 48;
		write(1, &digit, 1);
	}
}

/*int	main(void)
{
	ft_putnbr(2147483647);
	return (0);
}*/
