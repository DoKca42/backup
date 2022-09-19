/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:33:53 by lloison           #+#    #+#             */
/*   Updated: 2022/09/19 15:13:02 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parsing.h"
#include "ft_functional.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // a suppr

int	ft_result(t_position *pos, t_map **cmap)
{
	int	y;
	int	x;
	int	size;

	size = 0;
	y = 0;
	while (y <= ((*cmap)->height - size))
	{
		x = 0;
		while (x <= ((*cmap)->length - size))
		{
			if ((*cmap)->matrice[y][x] > size ||
				((*cmap)->matrice[y][x] == size &&
					x < (*pos).x && y <= (*pos).x))
			{
				size = (*cmap)->matrice[y][x];
				(*pos).x = x;
				(*pos).y = y;
			}
			x++;
		}
		y++;
	}
	return (size);
}

int	check_mini(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
}

int	ft_check(int y, int x, t_map **cmap)
{
	int	bas;
	int	droite;
	int	diago;

	if (y >= (*cmap)->height || x >= (*cmap)->length)
		return (0);
	if ((*cmap)->matrice[y][x] == -1)
	{
		bas = ft_check(y + 1, x, cmap);
		droite = ft_check(y, x + 1, cmap);
		diago = ft_check(y + 1, x + 1, cmap);
		(*cmap)->matrice[y][x] = 0;
		if ((*cmap)->map[y][x] == (*cmap)->empty)
		{
			(*cmap)->matrice[y][x] = 1 + check_mini(bas, droite, diago);
		}
	}
	return ((*cmap)->matrice[y][x]);
}

int	ft_init(t_map **cmap)
{
	int	a;
	int	b;

	(*cmap)->matrice = (int **)malloc(((*cmap)->height + 1) * sizeof(int *));
	if ((*cmap)->matrice == 0)
		return (-1);
	a = 0;
	while (a < (*cmap)->height)
	{
		b = 0;
		(*cmap)->matrice[a] = malloc((*cmap)->length * sizeof(int));
		if ((*cmap)->matrice[a] == 0)
			return (-1);
		while (b < (*cmap)->length)
		{
			(*cmap)->matrice[a][b] = -1;
			b++;
		}
		a++;
	}
	ft_check(0, 0, cmap);
	return (0);
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
			write(1, &((*map)->map[i][j]), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_position	pos;
	int			size;
	int			a;	// a supp
	int			b;	// a supp

	(void) argc;
	pos.x = 0;
	pos.y = 0;
	parse_file(argv[1], &map);
	display_map(&map);
	if (ft_init(&map) == -1)
		printf("Error\n");
	size = ft_result(&pos, &map);
	a = 0;
	while (a < (*map).height)
	{
		b = 0;
		while (b < (*map).length)
		{
			printf("%d ", (*map).matrice[a][b]);
			b++;
		}
		printf("\n");
		a++;
	}
	printf("\n\n");
	printf("Size: %d\nx: %d\ny: %d\n", size, pos.x, pos.y);
	//fill_square(&map, pos, 7);
	//display_map(&map);
	return (0);
}
