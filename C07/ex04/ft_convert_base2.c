/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:19:46 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/29 13:09:34 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*skip_space_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
	{
		i++;
	}
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			*sign = -(*sign);
		i++;
	}
	return (str + i);
}

int	find_digit(char digit, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (digit == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *str)
{
	int	len_str;
	int	i;
	int	j;

	len_str = 0;
	while (str[len_str])
		len_str++;
	if (len_str <= 1)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (-1);
			j++;
		}
		if (str[i] == '+' || str[i] == '-')
			return (-1);
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base_from)
{
	int	sign;
	int	result;
	int	i;
	int	digit;
	int	len_base_from;

	sign = 1;
	str = skip_space_sign(str, &sign);
	i = 0;
	result = 0;
	len_base_from = check_base(base_from);
	while (str[i])
	{
		digit = find_digit(str[i], base_from);
		if (digit >= 0)
			result = len_base_from * result + digit;
		else
			return (result * sign);
		i++;
	}
	if (result == 0)
		return (0);
	return (result * sign);
}
