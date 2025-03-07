/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:32:16 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/07 17:04:10 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	i = 0;
	if (length < 1)
		return (NULL);
	result = (int *)malloc(length * sizeof(int));
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
