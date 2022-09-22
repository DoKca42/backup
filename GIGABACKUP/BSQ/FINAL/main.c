/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:33:53 by lloison           #+#    #+#             */
/*   Updated: 2022/09/21 18:16:56 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "parsing.h"
#include "ft_functional.h"
#include "find_square.h"
#include "read_standard_input.h"
#include "display_functions.h"
#include <unistd.h>
#include <stdlib.h>

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
	else
	{
		read_standard_input();
	}
	return (0);
}
