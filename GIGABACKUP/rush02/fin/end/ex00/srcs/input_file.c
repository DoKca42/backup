/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:27:29 by dgoubin           #+#    #+#             */
/*   Updated: 2022/09/18 22:21:00 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_pars.h"
#include "parsing.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\n');
}

int	tab_length(char **str)
{
	int	cpt;

	cpt = 0;
	while (*(str++))
		cpt++;
	return (cpt);
}

int	count_nbr_of_ch(char *str)
{
	int	cpt;

	cpt = 0;
	while (*str)
	{
		if (*str >= '0' && *(str++) <= '9')
			cpt++;
		else
			return (cpt);
	}
	return (cpt);
}

t_parsed_input	input_modifier(char *str, t_parsed_input input
		, int cpt, int *error)
{
	int	minus;
	int	index;

	index = 0;
	minus = 1;
	while (*str && is_space(*str))
		str++;
	if (*str && *str == '+')
		str++;
	while (*str && *str <= '9' && *str >= '0')
	{
		if (cpt == 3)
		{
			cpt = 0;
			index++;
			input.nbr[index] = malloc(sizeof(char) * 3);
			if (input.nbr[index] == NULL)
				*error = 1;
		}
		input.nbr[index][cpt++] = *(str++);
	}
	if (*str || minus == -1)
		ft_error_in(error);
	input.size = tab_length(input.nbr);
	return (input);
}

struct	s_parsed_input	input_modifier_init(char *str, int *error)
{
	int					cpt;
	t_parsed_input		input;

	input.nbr = malloc(sizeof(char *) * count_nbr_of_ch(str));
	if (input.nbr == NULL)
		ft_error_in(error);
	input.nbr[0] = malloc(sizeof(char) * 3);
	if (input.nbr[0] == NULL)
		ft_error_in(error);
	cpt = (count_nbr_of_ch(str) % 3);
	if (cpt == 1)
	{
		input.nbr[0][0] = '0';
		input.nbr[0][1] = '0';
		cpt = 2;
	}
	else if (cpt == 2)
	{
		input.nbr[0][0] = '0';
		cpt = 1;
	}
	input = input_modifier(str, input, cpt, error);
	return (input);
}
