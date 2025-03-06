/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:11:05 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/16 23:14:50 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_any(char **tab, int (*f)(char *));
int	check_tab(char *tab);

int	main(void)
{
	char	*tab[4];

	tab[0] = "000";
	tab[1] = "000";
	tab[2] = "000";
	tab[3] = NULL;
	printf("result = %d\n", ft_any(tab, &check_tab));
	return (0);
}
