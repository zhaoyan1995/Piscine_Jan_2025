/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:28:52 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/15 11:37:06 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putnbr(int nb);
void	ft_foreach(int *tab, int length, void (*f)(int));

int	main(void)
{
	int	length;
	int	tab[5] = {1, 345, 2398, 54, 890};

	length = sizeof(tab) / sizeof(int);
	ft_foreach(tab, length, ft_putnbr);
	return (0);
}
