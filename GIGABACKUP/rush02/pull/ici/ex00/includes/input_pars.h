/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_pars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-vaul <mde-vaul@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:41:27 by mde-vaul          #+#    #+#             */
/*   Updated: 2022/09/18 18:00:49 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PARS_H
# define INPUT_PARS_H
# include <stdlib.h>

typedef struct s_parsed_input
{
	unsigned int	size;
	char			**nbr;
}	t_parsed_input;

int						is_space(char c);
int						tab_length(char **str);
int						count_nbr_of_ch(char *str);
struct s_parsed_input	input_modifier(char *str, t_parsed_input input,
							int cpt, int *error);
struct s_parsed_input	input_modifier_init(char *str, int *error);
#endif
