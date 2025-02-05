/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:45:13 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/30 14:04:03 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_memory_size(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len_total;
	int	len_sep;

	i = 0;
	len_total = 0;
	len_sep = ft_strlen(sep);
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
			len_total++;
		}
		i++;
		if (i < size && strs[i] != NULL)
			len_total = len_total + len_sep;
	}
	return (len_total);
}

void	ft_concatenate_strs(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			dest[k++] = strs[i][j++];
		l = 0;
		i++;
		while (sep[l] != '\0' && i < size && strs[i] != NULL)
		{
			dest[k] = sep[l];
			l++;
			k++;
		}	
	}
	dest[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		memory_size;

	if (size == 0)
	{
		dest = (char *)malloc(1);
		if (dest == NULL)
			return (NULL);
		dest [0] = '\0';
		return (dest);
	}
	memory_size = ft_memory_size(size, strs, sep);
	dest = (char *)malloc(sizeof(char) * (memory_size + 1));
	if (dest == NULL)
		return (NULL);
	ft_concatenate_strs(size, strs, sep, dest);
	return (dest);
}

/*#include <stdio.h>

int	main()
{
	int	size;
	char	*strs[4];
	char	*sep;
	char	*result;

	size = 3;
	strs[0] = "Coucou";
	strs[1] = "Lilou";
	strs[2] = "miao!!";
	strs[3] = NULL;
	sep = "--";
	result = ft_strjoin(size, strs, sep);
	if (result != NULL)
	{
		printf("%s\n", result);
		free(result);
	}
	else
		printf("memory allocation failed.\n");
	return (0);
}*/
