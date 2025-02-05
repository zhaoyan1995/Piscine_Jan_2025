/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:19:46 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/30 17:44:58 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base_from);
int	check_base(char *str);

int	ft_memory_size(int nbr, int len_base_to)
{
	int	memory_size;

	memory_size = 1;
	if (nbr == 0)
		return (memory_size);
	if (nbr < 0)
	{				
		memory_size++;
		if (nbr == -2147483648)
		{
			nbr /= len_base_to;
			memory_size++;
		}
		nbr = -nbr;
	}
	while (nbr >= len_base_to)
	{
		nbr /= len_base_to;
		memory_size++;
	}
	return (memory_size);
}

char	*ft_put_nbr(int res_dec, char *base_to, char *result, int memory)
{	
	int		len_base_to;

	len_base_to = check_base(base_to);
	result[memory--] = '\0';
	if (res_dec == 0)
		result[memory] = base_to[memory];
	if (res_dec < 0)
	{
		result[0] = '-';
		if (res_dec == -2147483648)
		{
			result[memory] = base_to[-(res_dec % len_base_to)];
			res_dec = -(res_dec / len_base_to);
			memory--;
		}
		else
			res_dec = -res_dec;
	}
	while (res_dec > 0)
	{
		result[memory] = base_to[res_dec % len_base_to];
		res_dec /= len_base_to;
		memory--;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len_base_to;
	int		len_base_from;
	int		result_decimal;
	int		memory_result;
	char	*result_base_to;

	len_base_to = check_base(base_to);
	len_base_from = check_base(base_from);
	if (len_base_to == -1 || len_base_from == -1)
		return (NULL);
	result_decimal = ft_atoi_base(nbr, base_from);
	memory_result = ft_memory_size(result_decimal, len_base_to);
	result_base_to = (char *)malloc(memory_result + 1);
	if (result_base_to == NULL)
		return (NULL);
	ft_put_nbr(result_decimal, base_to, result_base_to, memory_result);
	return (result_base_to);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*result_base_to;

	if (argc == 4)
	{
		//printf("char *nbr = %s\n", argv[1]);
		//printf("char *base_from = %s\n", argv[2]);
		//printf("char *base_to = %s\n", argv[3]);
		result_base_to = ft_convert_base(argv[1], argv[2], argv[3]);
		printf("lilou %s\n", result_base_to);
		free(result_base_to);
	}
	return (0);
}*/
