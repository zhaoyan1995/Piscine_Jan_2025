/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:19:46 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/05 18:52:09 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int		file;
	int		i;

	if (argc == 1)
	{
		write_to_file("stdin_map.txt");
		file = open("stdin_map.txt", O_RDONLY);
		check_solution(file, "stdin_map.txt");
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1)
			write(2, "map error\n", 10);
		else
			check_solution(file, argv[i]);
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
