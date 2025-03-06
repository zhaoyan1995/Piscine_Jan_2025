/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:37:22 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/17 15:43:24 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* we assume that the tab is ascending sorted and descending sorted at the very
 * first beginning, then we introduce the tab into the while loop, 
 * if f(tab[i], tab[i + 1]) is negative, then the flag "is_ascending" will be 
 * FALSE,so we change the value of the flag "is_ascending" as 0, 
 * it will no longer be able to become 1 untile the end, 
 * so does is_descending*/
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_ascending;
	int	is_descending;

	i = 0;
	is_ascending = 1;
	is_descending = 1;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			is_ascending = 0;
		if (f(tab[i], tab[i + 1]) < 0)
			is_descending = 0;
		i++;
	}
	if (is_ascending == 1 || is_descending == 1)
		return (1);
	return (0);
}
