/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:27:29 by dgoubin           #+#    #+#             */
/*   Updated: 2022/09/18 19:33:21 by mde-vaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_pars.h"
#include "parsing.h"
#include "generate_str.h"
#include <stdio.h>

void	free_memory(t_parsed_input input, t_dict dictparse, char *output)
{
	free(dictparse.k);
	free(dictparse.u);
	free(output);
}

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
	{
		dictparse = parsing_read(&error);
		if (error != 1)
		{
			int i = 0;
			while ( i <= 28)
			{
				printf("%d - ", dictparse.u[i].key);
				printf("%s\n",  dictparse.u[i].value);
				i++;
			}
			i = 0;
			while ( i < 12)
			{
				printf("%d - ", dictparse.k[i].key);
				printf("%s\n",  dictparse.k[i].value);
				i++;
			}
			output = generate_str(&dictparse, &input);
			printf("%s", output);
		}
	}
	free_memory(input, dictparse, output);
	return (0);
}
