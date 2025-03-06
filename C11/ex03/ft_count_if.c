/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZHAOYAN <ZHAOYan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:31:41 by ZHAOYAN           #+#    #+#             */
/*   Updated: 2025/02/19 17:02:55 by ZHAOYAN          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			result++;
		i++;
	}
	return (result);
}
