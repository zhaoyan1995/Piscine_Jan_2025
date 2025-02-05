/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_oldmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:55:44 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/04 19:27:25 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_rows(char **map, int row)
{
	int	i;

	i = row - 1;
	if (!map)
		return ;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}

//prerequisites function for save_input2
//here we only save the map
char	**save_input_map(char *buffer2, int row, int col, int i)
{
	int		j;
	int		k;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (row + 1));
	if (map == NULL)
		return (NULL);
	k = 0;
	while (i < row)
	{
		j = 0;
		map[i] = (char *)malloc(sizeof(char) * (col + 1));
		if (map[i] == NULL)
		{
			free_rows(map, i);
			return (NULL);
		}
		while (j < col && buffer2[k] != '\n' && buffer2[k] != '\0')
			map[i][j++] = buffer2[k++];
		map[i][j] = '\0';
		if (buffer2[k] == '\n')
			k++;
		i++;
	}
	return (map);
}

//once the map has been validated
//we use the function to save the arguments + map in the t_old
struct	s_old	*save_input2(char *buffer2, int row, int col)
{
	int		i;
	t_old	*tab;

	tab = (t_old *)malloc(1 * sizeof(t_old));
	if (tab == NULL)
		return (NULL);
	tab[0].row = row;
	if (col > 1 && row > 1)
		tab[0].col = col - 1;
	else
		tab[0].col = col;
	i = 0;
	while (buffer2[i])
	{
		if (buffer2[i] == '\n')
			break ;
		i++;
	}
	tab[0].plein = buffer2[--i];
	tab[0].obstacle = buffer2[--i];
	tab[0].vide = buffer2[--i];
	buffer2 = skip_first_line(buffer2);
	tab[0].map = save_input_map(buffer2, row, col, 0);
	return (tab);
}
