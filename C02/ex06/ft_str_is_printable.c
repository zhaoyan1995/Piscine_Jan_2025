/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:19:19 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/18 13:19:48 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
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
	char	str[4];

	str[0] = 32;
	str[1] = 15;
	str[2] = 126;
	str[3] = '\0';
	printf("ft_str_is_printable = %d\n", ft_str_is_printable(str));
	return (0);
}*/
