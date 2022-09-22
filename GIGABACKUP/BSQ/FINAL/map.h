/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:28:00 by lloison           #+#    #+#             */
/*   Updated: 2022/09/20 14:52:31 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	char	**map;
	int		length;
	int		height;
	char	obstacle;
	char	empty;
	char	full;
	int		**matrice;
}	t_map;
typedef struct s_position
{
	int	x;
	int	y;
}	t_position;
int		initialize_full_map(char *str, int length, t_map **map);
int		initialize_map(char *str, t_map **map);
void	free_map(t_map **map);
void	fill_square(t_map **map, t_position pos, int length);
#endif
