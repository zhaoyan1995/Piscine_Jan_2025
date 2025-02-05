/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:58:46 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/30 18:53:39 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		i++;
	return (i);
}

int	ft_strlen_charset(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && charset[j] != '\0')
		{
			if (str[i + j] == charset[j])
				j++;
			else
				break ;
			if (charset[j] == '\0')
				return (i);
		}
		i++;
	}
	return (i);
}

int	ft_count_word(char *str, char *charset)
{
	int	nbr_word;
	int	len_charset;

	nbr_word = 0;
	len_charset = ft_strlen(charset);
	while (*str != '\0')
	{
		while (*str != '\0' && ft_strlen_charset(str, charset) == 0)
			str += len_charset;
		if (*str != '\0' && ft_strlen_charset(str, charset) != 0)
		{
			str += ft_strlen_charset(str, charset);
			nbr_word++;
		}
	}
	return (nbr_word);
}

char	**ft_split_2(char **result, char *str, char *charset, int memory_total)
{
	int	j;
	int	k;
	int	memory_split;

	j = 0;
	while (j < memory_total && *str != '\0')
	{
		while (ft_strlen_charset(str, charset) == 0)
			str += ft_strlen(charset);
		memory_split = ft_strlen_charset(str, charset);
		result[j] = (char *)malloc(sizeof(char) * (memory_split + 1));
		if (result[j] == NULL)
		{
			result[j] = NULL;
			return (result);
		}
		k = 0;
		while (k < memory_split && *str != 0)
			result[j][k++] = *str++;
		result[j++][k] = '\0';
	}
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		memory_total;

	memory_total = ft_count_word(str, charset);
	result = (char **)malloc(sizeof(char *) * (memory_total + 1));
	if (result == NULL)
		return (NULL);
	result = ft_split_2(result, str, charset, memory_total);
	if (result == NULL)
		return (NULL);
	return (result);
}

/*#include <stdio.h>
int	main(void)
{
	int	i;
	char	*str;
	char	**result;
	char	*charset;

	str = "*123444**456*789*745**";
	charset = "*";
	result = ft_split(str, charset);
	i = 0;
	while (i < 4)
	{
		printf("result[i] = %s\n", result[i]);
		free(result[i]);
		i++;
	}
	printf("final result[i] = %s\n", result[i]);
	free(result);
	return (0);
}*/
