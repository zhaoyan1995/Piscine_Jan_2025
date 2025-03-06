/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:54:13 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/19 15:45:02 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

int	check_op(char *str)
{
	int		i;
	char	*operators;

	operators = "+-*/%";
	if (ft_strlen(str) != 1)
		return (-1);
	i = 0;
	while (operators[i])
	{
		if (str[0] == operators[i])
			return (i);
		i++;
	}
	return (-1);
}

void	calculate(int a, char *str, int b)
{
	int	(*tab[5])(int, int);
	int	nb_operator;
	int	result;

	tab[0] = &add;
	tab[1] = &soustraction;
	tab[2] = &multiple;
	tab[3] = &divide;
	tab[4] = &modulo;
	nb_operator = check_op(str);
	if (nb_operator == 3 && b == 0)
	{
		write(2, "Stop : division by zero\n", 24);
		return ;
	}
	else if (nb_operator == 4 && b == 0)
	{
		write(2, "Stop : modulo by zero\n", 22);
		return ;
	}
	result = tab[nb_operator](a, b);
	ft_putnbr(result);
}
