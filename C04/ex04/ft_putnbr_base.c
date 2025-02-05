/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:00:57 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/23 17:10:08 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_check_base(char *base)
{
	int	len_base;
	int	i;
	int	j;

	len_base = ft_strlen(base);
	if (len_base <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	return (len_base);
}

void	ft_put_digit(int nbr, char *base, int len_base)
{
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (nbr < 0)
	{	
		if (nbr == -2147483648)
		{	
			ft_put_digit((nbr / len_base), base, len_base);
		}
		else
		{	
			write(1, "-", 1);
			nbr = -nbr;
		}
	}
	if (nbr / len_base > 0)
		ft_put_digit(nbr / len_base, base, len_base);
	write(1, &base[nbr % len_base], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len_base;

	len_base = ft_check_base(base);
	if (len_base == 0)
		return ;
	ft_put_digit(nbr, base, len_base);
}

/*int	main(void)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putnbr_base(-2147483648, base);
	return (0);
}*/
