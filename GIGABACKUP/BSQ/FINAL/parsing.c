/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:32:20 by lloison           #+#    #+#             */
/*   Updated: 2022/09/20 17:29:19 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "is_file_valid.h"
#include "parsing.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	parse_file(char *file_name, t_map **map)
{
	int	line_length;

	line_length = is_file_valid(file_name);
	if (line_length == -1)
		return (-1);
	if (parsing_to_map(file_name, map, line_length) == -1)
		return (-1);
	if ((*map)->height == 0 || (*map)->length == 0)
		return (-1);
	return (0);
}

int	parsing_to_map(char *filename, t_map **map, int length)
{
	int		fd;
	char	buf[4096];
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	get_next_line(fd, buf);
	if (initialize_full_map(buf, length, map) == -1)
		return (-1);
	while (i < (*map)->height)
	{
		get_next_line(fd, (*map)->map[i]);
		i++;
	}
	close(fd);
	return (0);
}	
