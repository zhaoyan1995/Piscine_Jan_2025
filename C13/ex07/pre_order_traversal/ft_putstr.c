/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:35:37 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/15 18:36:33 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_convert_to_char(void *data)
{
	char	*str;

	str = (char *)data;
	ft_putstr(str);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + 48;
	write(1, &c, 1);
}

void	applyf(void *item, int current_level, int is_first_elem)
{
	if (is_first_elem == 1)
	{
		ft_putstr(" first element of the level ");
		ft_putnbr(current_level);
	}
	else
	{
		ft_putstr("!first element of the level ");
		ft_putnbr(current_level);
	}
	ft_putstr(" => ");
	ft_convert_to_char(item);
	ft_putstr("\n");
}
