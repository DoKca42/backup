/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:33:53 by lloison           #+#    #+#             */
/*   Updated: 2022/09/19 17:54:35 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parsing.h"
#include "ft_functional.h"
#include "find_square.h"
#include <unistd.h>
#include <stdio.h>

void	display_map(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->length)
		{
			write(1, &((*map)->map[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_foreach_files(char **argv, t_position pos, int size, int argc)
{
	int			i;
	t_map		*map;

	i = 1;
	map = 0;
	while (i <= argc)
	{
		if (parse_file(argv[i], &map) == -1)
		{
			write(2, "map error\n", 10);
			free_map(&map);
			return (0);
		}
		if (ft_init(&map) == -1)
		{
			free_map(&map);
			return (0);
		}
		write(1, "1", 1);
		size = ft_result(&pos, &map);
		write(1, "2", 1);
		if (size > 0)
			fill_square(&map, pos, size);
		display_map(&map);
		free_map(&map);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_position	pos;
	int			size;

	size = 0;
	pos.x = 0;
	pos.y = 0;
	if (argc > 1)
	{
		ft_foreach_files(argv, pos, size, argc);
	}
	return (0);
}
