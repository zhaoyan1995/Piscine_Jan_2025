/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:06:31 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/19 19:34:07 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	if (size > 0)
	{	
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Hello Lilau, comment ca va ?";
	char	dest[50];	

	printf("ft_strlcpy = %d\n", ft_strlcpy(dest, src, 10));
	printf("strlen(src) = %ld\n", strlen(src));
	printf("src = %s\n", src);
	printf("dest = %s\n", dest);
	return (0);
}*/
