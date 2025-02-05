/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:37:43 by hguo              #+#    #+#             */
/*   Updated: 2025/02/04 16:04:34 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	free_grid(int **grid, int x)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (i < x)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

void	free_old(t_old *old)
{
	int	i;

	if (!old)
		return ;
	if (!old->map)
		return ;
	i = 0;
	while (i < old->row)
	{
		free(old->map[i]);
		i++;
	}
	free(old->map);
	old->map = NULL;
	free(old);
}

void	free_print(t_map *print)
{
	if (!print)
		return ;
	if (print->map)
	{
		free_grid(print->map, print->row);
		print->map = NULL;
	}
	free(print);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
