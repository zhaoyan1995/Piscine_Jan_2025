/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:29:15 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/21 20:04:36 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		i++;
	}
	result = s1[i] - s2[i];
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "";
	s2 = "";
	printf("result = %d\n", ft_strcmp(s1, s2));
	return (0);
}*/
