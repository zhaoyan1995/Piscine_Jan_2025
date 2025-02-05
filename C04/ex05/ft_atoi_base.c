/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:00:57 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/23 16:39:57 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_skip_space(char *str, int *sign)
{	
	*sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
			str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = *sign *(-1);
		str++;
	}
	return (str);
}

int	ft_check_base(char *base)
{
	int	len_base;
	int	i;
	int	j;

	len_base = 0;
	while (base[len_base])
		len_base++;
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
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		i++;
	}
	return (len_base);
}

int	find_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;

	if (ft_check_base(base) == 0)
		return (0);
	sign = 1;
	str = ft_skip_space(str, &sign);
	i = 0;
	result = 0;
	while (str[i] != '\0')
	{		
		if (find_digit(str[i], base) >= 0)
			result = result * ft_check_base(base) + find_digit(str[i++], base);
		else
			return (0);
	}
	if (result == 0)
		return (result);
	return (sign * result);
}

/*#include <stdio.h>

int	main(void)
{
	char	*base;

	base = "0123456789abcdef";
	printf("result = %d\n", ft_atoi_base("02560", base));
	return (0);
}*/
