/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:52:31 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/19 21:36:45 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));
int		ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*tab[] = {"hello", "lilou", "comment", "ca", "va", NULL};
	int		i;

	i = 0;
	ft_advanced_sort_string_tab(tab, &ft_strcmp);
	while (tab[i])
	{
		printf("tab[%d] = %s\n", i, tab[i]);
		i++;
	}
	return (0);
}
