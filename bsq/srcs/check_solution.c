/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:13:07 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/06 14:51:00 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	check_solution(int file, char *argv)
{
	char	*buffer2;
	int		row;
	int		col;
	t_old	*old;
	t_map	*print;

	buffer2 = save_input(file, argv);
	row = count_line(buffer2);
	col = count_col(buffer2);
	if (check_map(buffer2) == 0)
	{
		old = save_input2(buffer2, row, col);
		print = init_map(*old);
		prep_map(print, *old);
		print_map(print, *old);
		free(buffer2);
		free_old(old);
		free_print(print);
	}
	else
	{
		write(2, "map error", 10);
		free(buffer2);
	}
}
