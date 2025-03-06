/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:13 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/19 15:45:22 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc != 4)
		return (1);
	else
	{
		if (check_op(argv[2]) == -1)
		{
			write(1, "0\n", 2);
			return (1);
		}
		else
		{
			a = ft_atoi(argv[1]);
			b = ft_atoi(argv[3]);
			calculate(a, argv[2], b);
			write(1, "\n", 1);
		}
	}
	return (0);
}
