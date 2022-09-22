/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:59:12 by lloison           #+#    #+#             */
/*   Updated: 2022/09/21 16:16:12 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "is_file_valid.h"
#include "ft_functional.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	is_file_valid(char *file_name)
{
	int		fd;
	char	buf[4096];
	char	valid_chars[2];
	int		return_value;
	int		nb_line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (get_next_line(fd, buf) == -1)
		return (-1);
	if (verify_first_line(buf, valid_chars) == -1)
		return (-1);
	nb_line = ft_atoi(buf);
	if (nb_line == 0)
		return (-1);
	return_value = is_file_valid2(fd, valid_chars, buf, nb_line);
	close(fd);
	return (return_value);
}

int	is_file_valid2(int fd, char *valid_chars, char *buf, int nb_line)
{
	int	i;
	int	length;
	int	cur_line_length;

	i = 0;
	while (i < nb_line)
	{
		if (i == 0)
		{
			length = get_next_line(fd, buf);
			if (length == -1)
				return (-1);
		}
		else
		{
			cur_line_length = get_next_line(fd, buf);
			if (cur_line_length != length)
				return (-1);
		}
		if (verify_line(buf, valid_chars) == -1)
			return (-1);
		i++;
	}
	return (length);
}

int	get_next_line(int fd, char *buf)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) && i < 4095)
	{
		if (c == '\n')
		{
			buf[i] = '\0';
			return (i);
		}
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
	return (-1);
}

int	verify_first_line(char *buf, char *valid_chars)
{
	int	i;
	int	length;

	i = 0;
	length = ft_strlen(buf);
	if (length < 4)
		return (-1);
	if (buf[length - 1] < 32 || buf[length - 1] > 126
		|| buf[length - 2] < 32 || buf[length - 2] > 126
		|| buf[length - 3] < 32 || buf[length - 3] > 126)
		return (-1);
	valid_chars[1] = buf[length - 2];
	valid_chars[0] = buf[length - 3];
	buf[length - 3] = '\0';
	if (ft_str_is_numeric(buf) == -1)
		return (-1);
	if (valid_chars[0] == valid_chars[1] || valid_chars[0] == buf[length - 1]
		|| valid_chars[1] == buf[length - 1])
		return (-1);
	return (0);
}

int	verify_line(char *buf, char *valid_chars)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] != valid_chars[0] && buf[i] != valid_chars[1])
			return (-1);
		i++;
	}
	return (0);
}
