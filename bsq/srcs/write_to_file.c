/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanzhao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:59:39 by yanzhao           #+#    #+#             */
/*   Updated: 2025/02/05 18:37:47 by yanzhao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	write_to_file(const char *filename)
{
	int		fd;
	int		byte_read;
	char	*buffer;

	buffer = (char *)malloc(1000000000);
	if (!buffer)
		return (1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		free(buffer);
		return (1);
	}
	byte_read = read(0, buffer, 1000000000);
	while (byte_read > 1)
	{
		write(fd, buffer, byte_read);
		byte_read = read(0, buffer, 1000000000);
	}
	free(buffer);
	close(fd);
	return (0);
}
