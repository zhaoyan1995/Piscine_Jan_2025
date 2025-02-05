/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:37:56 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/01 15:40:43 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_put_nbr(int nbr)
{
	char	digit;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		ft_put_nbr(-nbr);
		return ;
	}
	if (nbr > 9)
		ft_put_nbr(nbr / 10);
	digit = nbr % 10 + 48;
	write(1, &digit, 1);
}

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	if (par == NULL)
		return ;
	i = 0;
	while (par[i].str != 0)
	{
		ft_put_str(par[i].str);
		write(1, "\n", 1);
		ft_put_nbr(par[i].size);
		write(1, "\n", 1);
		ft_put_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
