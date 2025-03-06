/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:52:31 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/20 16:23:55 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*j => the j th round of bubble sorting process
i => number of string in tab
bubble sort : we always start from the i = 0 element
for each round, we pick up the biggest element and we put it at the end of 
the array, then we continue the bubble sorting for the rest of the array.
In bubble sort, we ALWAYS compare two elements SIDE BY SIDE.
Unlike the selected sort*/

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[i], tab[i + 1]) > 0)
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		j++;
	}
}
