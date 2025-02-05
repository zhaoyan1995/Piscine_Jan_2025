/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:46:42 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/18 10:49:10 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (*str == '\0')
		return (flag);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			flag = 1;
		else
		{
			flag = 0;
			return (flag);
		}
		i++;
	}
	return (flag);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "147d65";
	printf("str = %s\n", str);
	printf("ft_str_is_numeric = %d\n", ft_str_is_numeric(str));
	return (0);
}*/
