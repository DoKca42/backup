/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_standard_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:51:33 by lloison           #+#    #+#             */
/*   Updated: 2022/09/19 19:01:34 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parsing.h"
#include "ft_functional.h"
#include "find_square.h"
#include "is_file_valid.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	read_standard_input()
{
	t_map		*map;
	t_position	pos;
	int			size;
	char		buf[1000];
	int			i;
	char		valid_chars[2];

	clear_buffer(buf);
	i = 0;
	while (read(0, &buf[i], 1))
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			verify_first_line(buf, valid_chars);
			i = -1;
		}
		i++;
	}

}

void	clear_buffer(char *buf)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		buf[i] = '\0';
		i++;
	}
}
