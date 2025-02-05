/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:17:31 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/01 23:45:44 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_charset(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_charset(str[i], charset) == 1)
			return (i);
		i++;
	}
	return (i);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	nb_word;

	i = 0;
	nb_word = 0;
	while (str[i] != '\0')
	{
		while (ft_is_charset(str[i], charset) == 1)
			i++;
		if (str[i] == '\0')
			return (nb_word);
		while (ft_is_charset(str[i], charset) != 1)
			i++;
		nb_word++;
	}
	return (nb_word);
}

char	**ft_split2(char **result, char *str, char *charset, int memory_total)
{
	int	i;
	int	j;
	int	memory_split;

	i = 0;
	while (i < memory_total)
	{
		while (*str != '\0' && ft_is_charset(*str, charset) == 1)
			str++;
		if (*str == '\0')
			break ;
		memory_split = ft_strlen_charset(str, charset);
		result[i] = (char *)malloc(sizeof(char) * (memory_split + 1));
		if (result[i] == NULL)
		{
			result[i] = NULL;
			return (result);
		}
		j = 0;
		while (*str != '\0' && ft_is_charset(*str, charset) != 1)
			result[i][j++] = *str++;
		result[i++][j] = '\0';
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		memory_total;
	char	**result;

	if (*charset == '\0')
		memory_total = 1;
	else
		memory_total = count_word(str, charset);
	result = (char **)malloc(sizeof(char *) * (memory_total + 1));
	if (result == NULL)
		return (NULL);
	result = ft_split2(result, str, charset, memory_total);
	return (result);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	//int	nbr_word;
	char	**result;
	int	i;
	
	if (ac == 3)
	{
		//nbr_word = count_word(av[1], av[2]);
		result = ft_split(av[1], av[2]);
		//printf("nbr_word = %d\n", nbr_word);
		i = 0;
		while (result[i] != NULL)
		{	
			printf("result = %s\n", result[i]);
			free(result[i]);
			result[i] = NULL;
			i++;
		}
		printf("final result = %s\n", result[i]);
		free(result);
		result = NULL;
	}
	return (0);
}*/
