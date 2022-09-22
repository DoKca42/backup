/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_standard_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:51:33 by lloison           #+#    #+#             */
/*   Updated: 2022/09/21 18:17:35 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parsing.h"
#include "ft_functional.h"
#include "find_square.h"
#include "is_file_valid.h"
#include "read_standard_input.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	display_map(t_map **map);

void	read_standard_input(void)
{
	t_map		*map;
	t_data		*data;

	initialize_data(&data);
	map = 0;
	while (read(0, &(data->c), 1) && data->i < 4095)
	{
		data->buf[data->i] = data->c;
		if (data->is_error == 0)
		{
			if (data->first_line_done && data->nb_lign >= map->height)
				data->is_error = 1;
			else if (data->buf[data->i] == '\n')
			{
				read_buf(&data, &map);
				clear_buffer(data->buf);
				data->i = -1;
			}
		}
		data->i = data->i + 1;
	}
	if (map)
		map->map[data->nb_lign] = 0;
	read_standard_input2(&data, &map);
}

void	read_standard_input2(t_data **data, t_map **map)
{
	t_position	pos;

	pos.x = 0;
	pos.y = 0;
	if ((*data)->is_error == 1 || (*data)->first_line_done == 0
		|| (*data)->nb_lign != (*map)->height || (*map)->length == 0)
		write(2, "map error\n", 10);
	else
	{
		ft_init(map);
		(*data)->size = ft_result(&pos, map);
		if ((*data)->size > 0)
			fill_square(map, pos, (*data)->size);
		display_map(map);
	}
	free(*data);
	free_map(map);
}

void	read_buf(t_data **data, t_map **map)
{
	if ((*data)->first_line_done == 0)
	{
		(*data)->buf[(*data)->i] = '\0';
		if (!(r_verify_first_line((*data)->buf, (*data)->valid_chars) != -1
				&& initialize_map((*data)->buf, map) != -1))
			(*data)->is_error = 1;
		(*data)->first_line_done = 1;
	}
	else
	{
		(*data)->buf[(*data)->i] = '\0';
		if ((*data)->length == -1)
		{
			(*data)->length = ft_strlen((*data)->buf);
			(*map)->length = (*data)->length;
		}
		else if (ft_strlen((*data)->buf) != (*data)->length)
			(*data)->is_error = 1;
		if (verify_line((*data)->buf, (*data)->valid_chars) == -1)
			(*data)->is_error = 1;
		else
			(*map)->map[(*data)->nb_lign] = ft_strdup((*data)->buf);
		(*data)->nb_lign = (*data)->nb_lign + 1;
	}
	(*data)->i = (*data)->i - 1;
}

void	initialize_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	clear_buffer((*data)->buf);
	(*data)->i = 0;
	(*data)->first_line_done = 0;
	(*data)->is_error = 0;
	(*data)->nb_lign = 0;
	(*data)->length = -1;
	(*data)->buf[0] = '\0';
}

void	clear_buffer(char *buf)
{
	int	i;

	i = 0;
	while (i < 4096)
	{
		buf[i] = '\0';
		i++;
	}
}
