/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:37:22 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/17 15:43:40 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));
int	ft_cmp(int a, int b);

int	main(void)
{
	int	tab1[4] = {2, 4, 7, 8};
	int	tab2[4] = {8, -7, 4, 2};
	int	length;

	length = sizeof(tab1) / sizeof(int);
	printf("result of tab1 = %d\n", ft_is_sort(tab1, length, ft_cmp));
	printf("result of tab2 = %d\n", ft_is_sort(tab2, length, ft_cmp));
	return (0);
}
