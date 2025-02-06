/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:24:16 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/06 17:29:57 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	ft_any(char **tab, int(*f)(char *))
{
	int	result;
	int	nb_non_zero;
	int	i;
	int	j;

	i = 0;
	nb_non_zero = 0;
	result = 0;
	while (tab[i])
	{
		nb_non_zero = f(tab[i]);
		result = nb_non_zero + result;
		i++;
	}
	if (result == 0)
		return (0);
	else
		return (1);

}

int	ft_check(char *str)
{
	int	i;
	int	nb_non_zero;

	i = 0;
	nb_non_zero = 0;
	while (str[i])
	{
		if (str[i] != '0')
			nb_non_zero++;
		i++;
	}
	return (nb_non_zero);
}

int	main(void)
{
	char	*tab[] = {"124", "475", "324", NULL};

	printf("result = %d\n", ft_any(tab, &ft_check));
	return (0);
}
