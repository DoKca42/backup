/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:27:29 by dgoubin           #+#    #+#             */
/*   Updated: 2022/09/18 19:01:26 by mde-vaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_pars.h"
#include "parsing.h"
#include "generate_str.h"

int	main(int argc, char **argv)
{
	t_parsed_input	input;
	t_dict			dictparse;
	char			*output;
	int				error;

	error = 0;
	if (argc < 2 || argc > 3)
	{
		ft_error_in(&error);
		return (0);
	}
	input = input_modifier_init(argv[1], &error);
	if (error != 1)
		dictparse = parsing_read(&error);
	if (error != 1)
	{
		output = generate_str(&dictparse, &input);
		while (output)
			write(1, output++, 1);
	}
	return (0);
}
