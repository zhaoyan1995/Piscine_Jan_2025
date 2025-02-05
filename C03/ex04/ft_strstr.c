/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:17:21 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/01/22 01:57:14 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && to_find[j] != '\0')
		{
			if (str[i + j] == to_find[j])
				j++;
			else
				break ;
			if (to_find[j] == '\0')
				return (str + i);
		}
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*str2;

	str = "Hello Lilou!!!!";
	str2 = "";
	if (strstr(str, str2) != NULL)
		printf("%s\n", strstr(str, str2));
	printf("result = %s\n", ft_strstr(str, str2));
	return (0);
}*/
