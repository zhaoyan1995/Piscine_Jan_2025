/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:08:24 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/22 01:16:32 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	char	dest[50];
	char	*src;

	src = " World!";
	dest[0] = 'H';
	dest[1] = 'e';
	dest[2] = 'l';
	dest[3] = 'l';
	dest[4] = 'o';
	printf("dest = %s\n", dest);
	printf("src = %s\n", src);
	ft_strncat(dest, src, 3);
	printf("dest final = %s\n", dest);
	return (0);
}*/
