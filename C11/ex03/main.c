/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:31:41 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/19 17:04:41 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	count_non_zero(char *str);
int	ft_count_if(char **tab, int length, int (*f)(char *));

int	main(int argc, char **argv)
{
	int	result;

	if (argc > 1)
	{
		result = ft_count_if(argv + 1, argc - 1, &count_non_zero);
		printf("result = %d\n", result);
	}
	return (0);
}
