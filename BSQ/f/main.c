/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:33:53 by lloison           #+#    #+#             */
/*   Updated: 2022/09/19 18:38:29 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parsing.h"
#include "ft_functional.h"
#include "find_square.h"
#include <unistd.h>
#include <stdio.h>

void	display_matrice(t_map **map)
{
	for(int i = 0; i < (*map)->height; i++)
	{
		for(int j = 0; j < (*map)->length; j++)
			if ((*map)->matrice[i][j] >= 20)
				printf("%d", (*map)->matrice[i][j]);
			else
				printf(".");
		printf("\n");
	}
}
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
			if ((*map)->map[i][j] == (*map)->full)
				printf("\033[0;32m");
			printf("%c", (*map)->map[i][j]);
			printf("\033[0m");
			j++;
		}
		printf("\n");
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
	t_map		*map;

	i = 0;
	map = 0;
	while (++i < argc)
	{
		if (parse_file(argv[i], &map) == -1)
		{
			write(2, "map error\n", 10);
			ft_return_line(i, argc);
			free_map(&map);
			continue;
		}
		if (ft_init(&map) == -1)
		{
			free_map(&map);
			continue;
		}
		ft_print_res(pos, &map, size);
		free_map(&map);
		ft_return_line(i, argc);
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
