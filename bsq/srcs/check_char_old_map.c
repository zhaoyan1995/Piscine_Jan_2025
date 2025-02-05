/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_old_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:55:44 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/04 23:38:19 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_repete(char *buffer2)
{
	int		i;
	char	vide;
	char	obstacle;
	char	plein;

	i = 0;
	while (buffer2[i])
	{
		if (buffer2[i] == '\n')
			break ;
		i++;
	}
	obstacle = buffer2[i - 3];
	vide = buffer2[i - 2];
	plein = buffer2[i - 1];
	if (obstacle == vide || obstacle == plein || vide == plein)
		return (-1);
	return (0);
}

//prerequisites function for check_char(char *buffer2)
int	check_char2(char c, char obstacle, char vide)
{
	if (c != obstacle && c != vide && c != '\n')
		return (-1);
	if (!(c >= 32 && c <= 126) && c != '\n')
		return (-1);
	return (0);
}

//check if the characters from the map file match the character
//from the 1st line of the map file
//if not return value == -1
//return value => input for function check_map(buffer2)
int	check_char(char *buffer2)
{
	int		i;
	char	vide;
	char	obstacle;

	i = 0;
	while (buffer2[i])
	{
		if (buffer2[i] == '\n')
			break ;
		i++;
	}
	i -= 2;
	obstacle = buffer2[i];
	vide = buffer2[--i];
	buffer2 = skip_first_line(buffer2);
	i = 0;
	while (buffer2[i])
	{
		if (check_char2(buffer2[i], obstacle, vide) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	check_map(char *buffer2)
{
	int	nbr_line;

	nbr_line = count_line(buffer2);
	if (nbr_line == -1)
		return (-1);
	else if (check_nbr_line(buffer2, nbr_line) == -1)
		return (-1);
	else if (check_repete(buffer2) == -1)
		return (-1);
	else if (check_char(buffer2) == -1)
		return (-1);
	else
		return (0);
}
