/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hguo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:39:30 by hguo              #+#    #+#             */
/*   Updated: 2025/02/04 21:19:22 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	convert_map(char c, char obstacle)
{
	if (c == obstacle)
		return (0);
	else
		return (1);
}
//convertir les signes (type de char) dans map -> nombre 0 et 1 (int)

int	**copy_grid(t_old old)
{
	int	**new;
	int	i;
	int	j;

	i = 0;
	new = (int **)malloc(old.row * sizeof(int *));
	if (!new)
		return (NULL);
	while (i < old.row)
	{
		j = 0;
		new[i] = (int *)malloc(old.col * sizeof(int));
		if (!new[i])
		{
			free_grid(new, i - 1);
			return (NULL);
		}
		while (j < old.col)
		{
			new[i][j] = convert_map(old.map[i][j], old.obstacle);
			j++;
		}
		i++;
	}
	return (new);
}
//utiliser les valeurs dans struct, 
//allouer un tableau bidimentionnel (type de int)
//et copier les contenus dedans

int	**calcul_size(t_old old, int **new)
{
	int	i;
	int	j;

	i = 1;
	while (i < old.row)
	{
		j = 1;
		while (j < old.col)
		{
			if (new[i][j] == 0)
				new[i][j] = 0;
			else
				new[i][j] = 1 + ft_min(new[i - 1][j],
						new[i][j - 1],
						new[i - 1][j - 1]);
			j++;
		}
		i++;
	}
	return (new);
}
//on calcul le biggest Square size de chaque point, on commence par (1,1)
//parce qu'on prend le new[i][j] comme coin inferieur droit du carre.
//EXPLICATION de ft_min() : 
//le valeur de new[i][j] est le size de Square de ce point
//si on veut grandir Square, 
//les haut/gauche/gauch haut(3 points) doivent tous etre vide
//cest a dire que tous doivent etre 1,
//du coup on utilise ft_min(dans fichier basic1.c)
//pour verifier si le valeur de tous les trois points sont 1
//si non, le size peut pas grandir

t_grid	find_grid(int **new, t_old old)
{
	t_grid	grid;
	int		i;
	int		j;

	i = 0;
	grid.size = 0;
	grid.x = -1;
	grid.y = -1;
	while (i < old.row)
	{
		j = 0;
		while (j < old.col)
		{
			if (new[i][j] > grid.size)
			{
				grid.size = new[i][j];
				grid.x = i;
				grid.y = j;
			}
			j++;
		}
		i++;
	}
	return (grid);
}
//on cherche le size et la position de Biggest Square dans le map  

void	fill_grid(int **map, t_grid grid)
{
	int	i;
	int	j;

	if (grid.x == -1 || grid.size == 0 || grid.y == -1)
		return ;
	i = grid.x;
	while (i > grid.x - grid.size)
	{
		j = grid.y;
		while (j > grid.y - grid.size)
		{
			map[i][j] = 2;
			j--;
		}
		i--;
	}
}
// Nous remplissons le carré du coin inférieur droit au coin supérieur gauche 
// avec le chiffre 2 (signifie plein)
// 0 signifie obstacle, 1 signifie vide
