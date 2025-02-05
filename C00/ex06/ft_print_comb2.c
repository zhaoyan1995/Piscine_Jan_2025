/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:39:11 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/17 20:40:15 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		n1;
	int		n2;
	char	buffer[2];

	n1 = 0;
	while (n1 <= 99)
	{
		n2 = n1 + 1;
		while (n2 <= 99)
		{
			buffer[0] = n1 / 10 + '0';
			buffer[1] = n1 % 10 + '0';
			write(1, &buffer[0], 1);
			write(1, &buffer[1], 1);
			write(1, " ", 1);
			buffer[0] = n2 / 10 + '0';
			buffer[1] = n2 % 10 + '0';
			write(1, &buffer[0], 1);
			write(1, &buffer[1], 1);
			if (!(n1 == 98 && n2 == 99))
				write (1, ", ", 2);
			n2++;
		}
		n1++;
	}
}
