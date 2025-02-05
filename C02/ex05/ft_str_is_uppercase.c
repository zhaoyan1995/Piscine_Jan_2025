/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:58:30 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/18 11:01:01 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (*str == '\0')
		return (flag);
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
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

	str = "IDF";
	printf("str = %s\n", str);
	printf("ft_str_is_uppercase = %d\n", ft_str_is_uppercase(str));
	return (0);
}*/
