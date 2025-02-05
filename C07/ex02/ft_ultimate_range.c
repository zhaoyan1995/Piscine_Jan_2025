/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:46:10 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/30 19:20:55 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size_range;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size_range = max - min;
	*range = (int *)malloc(size_range * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < size_range)
	{	
		(*range)[i] = min + i;
		i++;
	}
	return (size_range);
}

/*#include <stdio.h>

int	main(void)
{
	int	*range;
	int	i;
	int	size;

	size = ft_ultimate_range(&range, 3, 6);
	if (size == -1)
	{
		printf("failed to allocate the memory\n");	
		return (1);
	}
	if (size == 0)
	{
		printf("invalide range of min max, min >= max\n");	
		return (0);
	}
	i = 0;
	while (i < size)
	{
		printf("range[%d] = %d\n", i, range[i]);
		i++;
	}
	free(range);
	return (0);
}*/
