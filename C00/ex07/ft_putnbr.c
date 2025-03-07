/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:19:43 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/15 20:57:22 by yanzhao          ###   ########.fr       */
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
			write(1, "2", 1);
			nb = nb % 1000000000;
		}	
		ft_putnbr(-nb);
	}
	else
	{
		if (nb / 10 != 0)
			ft_putnbr(nb / 10);
		digit = nb % 10 + '0';
		write(1, &digit, 1);
	}
}
