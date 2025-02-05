/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:55:43 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/17 23:21:06 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (*str == '\0')
		return (flag);
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
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

	str = "";
	printf("str = %s\n", str);
	printf("ft_str_is_alpha = %d\n", ft_str_is_alpha(str));
	return (0);
}*/
