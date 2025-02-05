/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:16:19 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/22 15:27:52 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_initial_dest;
	unsigned int	len_src;
	unsigned int	i;
	unsigned int	j;

	len_initial_dest = 0;
	len_src = 0;
	while (dest[len_initial_dest] != '\0')
		len_initial_dest++;
	while (src[len_src] != '\0')
		len_src++;
	if (size == 0)
		return (len_src);
	if (size <= len_initial_dest)
		return (len_src + size);
	i = len_initial_dest;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (len_src + len_initial_dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[5];
	char	src[] = "exo";

	dest[0] = 'H';
	dest[1] = 'e';
	dest[2] = 'l';
	dest[3] = 'l';
	dest[4] = 'o';
	printf("dest = %s\n", dest);
	printf("src = %s\n", src);
	printf("strlen dest is %ld\n", strlen(dest));
	printf("strlen src is %ld\n", strlen(src));
	printf("result = %d\n", ft_strlcat(dest, src, 3));
	printf("dest final = %s\n", dest);
	return (0);
}*/
