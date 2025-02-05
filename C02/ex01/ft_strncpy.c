/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 21:22:32 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/21 21:29:02 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	i;	
	char	*src;
	char	dest[50];

	src = "hello lilou";
	strncpy(dest, src, 45);
	i = 0;	
	printf("sizeof(dest) = %ld\n", sizeof(dest));
	while (i < sizeof(dest) / 4)
	{
		printf("dest[%d] = %c\n", i, dest[i]);
		i++;
	}
	printf("dest[35] = %c\n", dest[35]);
	return (0);
}*/
