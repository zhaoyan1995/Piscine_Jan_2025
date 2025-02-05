/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <yanzhao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:07:59 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/16 16:15:37 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}

/*#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "Hello Lilou!\n";
	printf("the length of the str is %d\n", ft_strlen(str));
	return (0);
}*/
