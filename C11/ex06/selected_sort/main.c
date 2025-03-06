/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:17:24 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/20 15:59:46 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_cmp(char *s1, char *s2);
void	ft_swap(char **s1, char **s2);
void	ft_sort_string_tab(char **tab);

int	main(void)
{
	int		i;
	char	*tab[] = {"zebra", "noudle", "apple", "banana", NULL};

	ft_sort_string_tab(tab);
	i = 0;
	while (tab[i])
	{
		printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}
	return (0);
}
