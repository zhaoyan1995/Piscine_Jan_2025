/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_col_oldmap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:55:44 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/05 15:05:45 by hguo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//save the input map file in a buffer named buffer2, sized by malloc
char	*save_input(int file, char *argv)
{
	size_t	byte_read;
	size_t	byte_total;
	char	buffer[100];
	char	*buffer2;
	size_t	i;

	byte_total = 0;
	byte_read = read(file, buffer, sizeof(buffer));
	while (byte_read > 0)
	{
		byte_total = byte_read + byte_total;
		byte_read = read(file, buffer, sizeof(buffer));
	}
	buffer2 = (char *)malloc(sizeof(char) * (byte_total + 1));
	if (buffer2 == NULL)
		return (NULL);
	i = 0;
	while (i < byte_total)
		buffer2[i++] = '\0';
	close(file);
	file = open(argv, O_RDONLY);
	read(file, buffer2, byte_total - 1);
	buffer2[byte_total] = '\0';
	close(file);
	return (buffer2);
}

//skip the first line of map file (ex : 5.ox\n)
char	*skip_first_line(char *buffer2)
{
	while (*buffer2)
	{
		if (*buffer2 == '\n')
			break ;
		buffer2++;
	}
	return (buffer2 + 1);
}

//input function to count only the nbr of col for the 2nd line of map.
//return value => input for function count_line(car *buffer2)
int	count_col_first(char *buffer2)
{
	int	nb_col_first;

	nb_col_first = 0;
	while (*buffer2)
	{
		if (*buffer2 == '\n')
			break ;
		buffer2++;
		nb_col_first++;
	}
	return (nb_col_first);
}

//Check the number of lines from the 2nd line.
//If we don't have the same col for each line then we return -1.
//return value => input for function check_map(buffer2).
int	count_line(char *buffer2)
{
	int	nb_line;
	int	nb_col_first;
	int	nb_col;

	nb_line = 1;
	buffer2 = skip_first_line(buffer2);
	nb_col_first = count_col_first(buffer2);
	if (nb_col_first == 0)
		return (-1);
	nb_col = -1;
	while (nb_col++, *buffer2)
	{
		if (*buffer2 == '\n')
		{
			if (nb_col_first != nb_col)
				return (-1);
			buffer2++;
			if (*buffer2 == '\0')
				break ;
			nb_col = 0;
			nb_line++;
		}
		buffer2++;
	}
	return (nb_line);
}

//Check the coherence between the digit number of the first line
//and the number of the line in the map file
//in case of KO, return value == -1
//return value => input for function check_map(buffer2)
int	check_nbr_line(char *buffer2, int nb_line)
{
	int	result;
	int	i;
	int	size;

	result = 0;
	size = 0;
	while (buffer2[size] && buffer2[size] != '\n' && buffer2[size])
		size++;
	size -= 3;
	i = 0;
	while (buffer2[i] == ' ' || buffer2[i] == '\f' || buffer2[i] == '\n'
		|| buffer2[i] == '\r' || buffer2[i] == '\t' || buffer2[i] == '\v')
		i++;
	while (buffer2[i] != '\0' && i < size)
	{
		if (buffer2[i] >= '0' && buffer2[i] <= '9')
			result = result * 10 + (buffer2[i] - 48);
		else
			break ;
		i++;
	}
	if (result != nb_line)
		return (-1);
	return (result);
}
