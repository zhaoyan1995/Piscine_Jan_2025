/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:39:49 by hguo              #+#    #+#             */
/*   Updated: 2025/02/04 21:29:43 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**alloc_map_array(int row, int col)
{
	int	**map;
	int	i;
	int	j;

	map = (int **)malloc(row * sizeof(int *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < row)
	{
		map[i] = (int *)malloc(col * sizeof(int));
		if (!map[i])
		{
			free_grid(map, i - 1);
			return (NULL);
		}
		j = 0;
		while (j < col)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

t_map	*init_map(t_old old)
{
	t_map	*print;

	print = (t_map *)malloc(sizeof(t_map));
	if (!print)
		return (NULL);
	(*print).row = old.row;
	(*print).col = old.col;
	print->map = alloc_map_array(old.row, old.col);
	if (!print->map)
	{
		free(print);
		return (NULL);
	}
	return (print);
}

void	fill_digitmap(t_map *print, t_old old)
{
	int	i;
	int	j;
	int	**new;

	new = copy_grid(old);
	new = calcul_size(old, new);
	i = 0;
	while (i < (*print).row)
	{
		j = 0;
		while (j < (*print).col)
		{
			print->map[i][j] = new[i][j];
			j++;
		}
		i++;
	}
	free_grid(new, (*print).row);
}

void	prep_map(t_map *print, t_old old)
{
	t_grid	grid;

	fill_digitmap(print, old);
	grid = find_grid(print->map, old);
	print->grid.x = grid.x - grid.size + 1;
	print->grid.y = grid.y - grid.size + 1;
	print->grid.size = grid.size;
	fill_grid(print->map, grid);
}
