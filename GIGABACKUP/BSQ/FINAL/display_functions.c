/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:45:32 by lloison           #+#    #+#             */
/*   Updated: 2022/09/21 18:25:43 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parsing.h"
#include "ft_functional.h"
#include "find_square.h"
#include <unistd.h>
#include <stdlib.h>

void	breaking_the_free(char **argv, int i, int size, int argc);

void	display_map(t_map **map)
{
	int	i;

	i = 0;
	while (i < (*map)->height)
	{
		write(1, ((*map)->map[i]), (*map)->length);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_return_line(int i, int argc)
{
	if (i < argc - 1)
		write(1, "\n", 1);
}

void	ft_print_res(t_position pos, t_map **map, int size)
{
	size = ft_result(&pos, map);
	if (size > 0)
		fill_square(map, pos, size);
	display_map(map);
}

int	ft_foreach_files(char **argv, t_position pos, int size, int argc)
{
	int			i;

	(void) pos;
	i = 0;
	while (++i < argc)
	{
		breaking_the_free(argv, i, size, argc);
	}
	return (0);
}

void	breaking_the_free(char **argv, int i, int size, int argc)
{
	t_map		*map;
	t_position	pos;

	pos.x = 0;
	pos.y = 0;
	map = 0;
	if (parse_file(argv[i], &map) == -1)
	{
		write(2, "map error\n", 10);
		ft_return_line(i, argc);
		free_map(&map);
		return ;
	}
	if (ft_init(&map) == -1)
	{
		free_map(&map);
		return ;
	}
	ft_print_res(pos, &map, size);
	free_map(&map);
	ft_return_line(i, argc);
}
