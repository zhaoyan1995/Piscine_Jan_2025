/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmourvil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:39:57 by tmourvil          #+#    #+#             */
/*   Updated: 2025/01/18 19:19:16 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_put_line_col(int col, int line, int x, int y)
{
	if ((line == 0 || line == y - 1) && (col == 0 || col == x - 1))
		ft_putchar('o');
	else if ((line == 0 || line == y - 1)
		&& !(col == 0 || col == x - 1))
		ft_putchar('-');
	else
	{
		if (col == 0 || col == x - 1)
			ft_putchar('|');
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
