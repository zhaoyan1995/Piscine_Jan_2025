/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:06:22 by yanzhao           #+#    #+#             */
/*   Updated: 2025/01/21 21:57:39 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_put_hex_str(char *str, int size)
{
	int		i;
	int		num_dec;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (i < 16 && str[i] != '\0' && i < size)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		num_dec = (int)str[i++];
		write(1, &hex[num_dec / 16], 1);
		write(1, &hex[num_dec % 16], 1);
		if (i < 16 && str[i] == '\0')
		{
			if (i % 2 == 0)
				write(1, " ", 1);
			write(1, "00", 2);
			i++;
			break ;
		}
	}
	write(1, " ", 1);
	return (i);
}

void	ft_put_hex_sixteen_index(unsigned long num_dec)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num_dec == 0)
	{
		return ;
	}
	if (num_dec >= 16)
		ft_put_hex_sixteen_index(num_dec / 16);
	write(1, &hex[num_dec % 16], 1);
}

void	ft_put_addr(unsigned long num_decimal)
{
	int				num_of_non_zero;
	unsigned long	num_decimal2;

	num_of_non_zero = 1;
	num_decimal2 = num_decimal;
	while (num_decimal2 >= 16)
	{
		num_decimal2 /= 16;
		num_of_non_zero++;
	}
	while (16 - num_of_non_zero > 0)
	{
		write(1, "0", 1);
		num_of_non_zero++;
	}
	ft_put_hex_sixteen_index(num_decimal);
	write(1, ":", 1);
}

int	ft_put_text(char *str, int count, int size, int end_index)
{
	int	i;
	int	nbr_space;

	nbr_space = 39 - end_index * 2 - end_index / 2;
	if (end_index % 2 != 0)
		nbr_space--;
	if (end_index != 16)
		write(1, "                                       ", nbr_space + 1);
	i = 0;
	while (i < 16 && i < (size - count) && str[i] != '\0' && count < size)
	{
		if (((int)str[i] >= 0 && (int)str[i] <= 31) || (int)str[i] == 127)
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
		if (i < 16 && str[i] == '\0')
			write(1, ".", 1);
	}
	return (i);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	count;
	char			*str;
	int				end_index;
	int				end_index2;

	count = 0;
	while (count < size)
	{
		ft_put_addr((unsigned long)addr);
		end_index = ft_put_hex_str((char *)addr, size - count);
		str = (char *)addr;
		end_index2 = ft_put_text(str, count, size, end_index);
		write(1, "\n", 1);
		if (str[end_index2] == '\0')
			break ;
		addr = addr + 16;
		count += 16;
	}
	if ((count + end_index2) % 16 == 0 && size != 0 && str[end_index2] == '\0')
	{
		ft_put_addr((unsigned long)(addr + 16));
		write(1, " 00                                      .\n", 43);
	}
	return (addr);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	void	*add;

	str = "xxdfdsfrdipdriphiqhibdfdfdfsdfddfdsffsdfdsiiidlilouIDdd\n\t\rc\t est
       	u\ntout\tcde qu on peut faire avec\t\n\tprint_memory\t\r\n\alol.lol\n ";
	add = ft_print_memory(str, strlen(str));
	//printf("\t%ld", strlen(str));
	//printf("\n00%p\n", add);
	return (0);
}*/
