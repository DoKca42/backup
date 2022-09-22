/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:28:12 by lloison           #+#    #+#             */
/*   Updated: 2022/09/21 18:16:49 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ft_functional.h"
#include <stdlib.h>
#include <unistd.h>

int	initialize_full_map(char *str, int length, t_map **map)
{
	int	i;

	i = 0;
	*map = (t_map *) malloc(sizeof(t_map));
	if (*map == 0)
		return (-1);
	(*map)->length = length;
	(*map)->empty = str[ft_strlen(str) - 3];
	(*map)->obstacle = str[ft_strlen(str) - 2];
	(*map)->full = str[ft_strlen(str) - 1];
	str[ft_strlen(str) - 3] = '\0';
	(*map)->height = ft_atoi(str);
	(*map)->map = (char **) malloc(sizeof(char *) * ((*map)->height + 1));
	(*map)->map[(*map)->height] = 0;
	(*map)->matrice = 0;
	if ((*map)->map == 0)
		return (-1);
	while (i < (*map)->height)
	{
		(*map)->map[i] = (char *) malloc(sizeof(char) * (length + 1));
		if ((*map)->map[i] == 0)
			return (-1);
		i++;
	}
	return (0);
}

int	initialize_map(char	*str, t_map **map)
{
	int	size;

	size = ft_strlen(str);
	*map = (t_map *) malloc(sizeof(t_map));
	if (*map == 0)
		return (-1);
	(*map)->empty = str[size - 3];
	(*map)->obstacle = str[size - 2];
	(*map)->full = str[size - 1];
	str[size - 3] = '\0';
	(*map)->height = ft_atoi(str);
	(*map)->map = (char **) malloc(sizeof(char *) * ((*map)->height + 1));
	size = 0;
	while (size < (*map)->height)
		(*map)->map[size++] = 0;
	(*map)->map[(*map)->height] = 0;
	(*map)->matrice = 0;
	if ((*map)->height <= 0)
		return (-1);
	if ((*map)->map == 0)
		return (-1);
	return (0);
}

void	free_map(t_map **map)
{
	int	i;

	i = 0;
	if ((*map))
	{
		while ((*map)->map && (*map)->map[i])
		{
			free((*map)->map[i]);
			i++;
		}
		if ((*map)->map != 0)
			free ((*map)->map);
		i = 0;
		while ((*map)->matrice && (*map)->matrice[i])
		{
			free((*map)->matrice[i]);
			i++;
		}
		if ((*map)->matrice != 0)
			free((*map)->matrice);
		free((*map));
	}
	*map = 0;
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
