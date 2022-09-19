/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:28:12 by lloison           #+#    #+#             */
/*   Updated: 2022/09/19 15:09:02 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ft_functional.h"
#include <stdlib.h>

int	initialize_map(char *str, int length, t_map **map)
{
	int	i;

	i = 0;
	*map = (t_map *) malloc(sizeof(t_map));
	if (*map == 0)
		return (-1);
	(*map)->length = length;
	(*map)->height = ft_atoi(str);
	(*map)->map = (char **) malloc(sizeof(char *) * (*map)->height);
	if ((*map)->map == 0)
		return (-1);
	while (i < (*map)->height)
	{
		(*map)->map[i] = (char *) malloc(sizeof(char) * length);
		if ((*map)->map[i] == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	(*map)->empty = str[i];
	(*map)->obstacle = str[i + 1];
	(*map)->full = str[i + 2];
	return (0);
}

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	while ((*map)->map[i])
	{
		free((*map)->map[i]);
		i++;
	}
	free ((*map)->map);
	i = 0;
	while ((*map)->matrice[i])
	{
		free((*map)->matrice[i]);
		i++;
	}
	free((*map)->matrice);
	free((*map));
}

void	fill_square(t_map **map, t_position pos, int length)
{
	int	i;
	int	j;

	i = pos.y;
	while (i < pos.y + length)
	{
		j = pos.x;
		while (j < pos.x + length)
		{
			(*map)->map[i][j] = (*map)->full;
			j++;
		}
		i++;
	}
}
