/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:17:24 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/03/07 18:33:00 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_swap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

int	ft_len(char **tab)
{
	int	length;

	length = 0;
	while (tab[length])
		length++;
	return (length);
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	length;

	length = ft_len(tab);
	j = 1;
	while (j < length)
	{
		i = 0;
		while (i < length - j)
		{
			if (ft_cmp(tab[i], tab[i + 1]) > 0)
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		j++;
	}
}
