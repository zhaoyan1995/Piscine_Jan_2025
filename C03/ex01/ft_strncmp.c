/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:52:17 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/21 20:03:20 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				result;

	i = 0;
	result = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		i++;
	}
	if (i < n)
		result = s1[i] - s2[i];
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "lilouhihhhh";
	s2 = "lilouhi";
	printf("result = %d\n", ft_strncmp(s1, s2, 7));
	return (0);
}*/
