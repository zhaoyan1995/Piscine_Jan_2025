/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:16:02 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/23 16:43:38 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;

	str = "hello world";
	printf("%d\n", ft_strlen(str));
	printf("%ld\n", strlen(str));
	return (0);
}*/
