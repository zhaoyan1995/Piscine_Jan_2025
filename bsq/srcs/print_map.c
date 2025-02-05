/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:28:27 by hguo              #+#    #+#             */
/*   Updated: 2025/02/04 21:48:14 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_cell(t_map *print, t_old old, int i, int j)
{
	int	x;
	int	y;
	int	size;

	x = (*print).grid.x;
	y = (*print).grid.y;
	size = (*print).grid.size;
	if ((*print).map[i][j] == 0)
		ft_putchar(old.obstacle);
	else if (((*print).map[i][j] == 2) && (i < x + size && i >= x)
			&& (j < y + size && j >= y))
		ft_putchar(old.plein);
	else
		ft_putchar(old.vide);
}

void	print_map(t_map *print, t_old old)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*print).row)
	{
		j = 0;
		while (j < (*print).col)
		{
			print_cell(print, old, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
