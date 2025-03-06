/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 10:32:16 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/15 11:36:10 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));
int	ft_double(int nb);

int	main(void)
{
	int	tab[] = {32, 56, 43, 104};
	int	*result;
	int	length;
	int	i;

	length = sizeof(tab) / sizeof(int);
	result = ft_map(tab, length, &ft_double);
	i = 0;
	while (i < length)
	{
		printf("result[%d] = %d\n", i, result[i]);
		i++;
	}
	free(result);
	return (0);
}
