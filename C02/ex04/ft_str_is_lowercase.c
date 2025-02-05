/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:52:05 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/18 10:57:57 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (*str == '\0')
		return (flag);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
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

	str = "aAd";
	printf("str = %s\n", str);
	printf("ft_str_is_lowercase = %d\n", ft_str_is_lowercase(str));
	return (0);
}*/
