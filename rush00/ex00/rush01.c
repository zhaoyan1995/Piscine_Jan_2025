/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 20:41:45 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/19 13:04:29 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_line_col(int col, int line, int x, int y)
{
	if (line == 0 && col == 0)
		ft_putchar('/');
	else if (line == 0 && col == x - 1)
		ft_putchar('\\');
	else if (line == y - 1 && col == 0)
		ft_putchar('\\');
	else if (line == y - 1 && col == x - 1)
		ft_putchar('/');
	else if (line == 0 && (col != 0 && col != x - 1))
		ft_putchar('*');
	else if (line == y - 1 && (col != 0 && col != x - 1))
		ft_putchar('*');
	else
	{
		if (col == 0 || col == x - 1)
			ft_putchar('*');
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
