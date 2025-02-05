/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:04:22 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/15 22:34:57 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_generate_digit(char buffer[], int index, int size_buffer, int digit)
{
	int		i;
	char	nbr;

	if (index == size_buffer)
	{
		i = 0;
		while (i < size_buffer)
		{	
			nbr = buffer[i];
			write(1, &nbr, 1);
			i++;
		}
		if (buffer[0] != 10 - size_buffer + 48)
			write(1, ", ", 2);
	}
	while (digit <= 9)
	{
		buffer[index] = digit + 48;
		if (index == size_buffer)
			break ;
		ft_generate_digit(buffer, index + 1, size_buffer, digit + 1);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	char	buffer[10];

	if (n > 0 && n < 10)
	{
		ft_generate_digit(buffer, 0, n, 0);
	}
	else
		return ;
}
