/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:47:01 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/18 22:03:46 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_line_col(int col, int line, int x, int y)
{
	if ((col == 0 && line == 0)
		|| (col == x - 1 && col != 0 && line == y - 1 && line != 0))
		ft_putchar('A');
	else if ((col == x - 1 && line == 0) || (col == 0 && line == y - 1))
		ft_putchar('C');
	else if ((line == 0 || line == y - 1) && !(col == 0 || col == x - 1))
		ft_putchar('B');
	else
	{
		if (col == 0 || col == x - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	col;
	int	line;

	line = 0;
	while (line < y)
	{
		col = 0;
		while (col < x)
		{
			ft_put_line_col(col, line, x, y);
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}
