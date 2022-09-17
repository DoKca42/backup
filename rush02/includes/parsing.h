/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:06:22 by loculy            #+#    #+#             */
/*   Updated: 2022/09/17 16:40:59 by mde-vaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_parsing
{
	unsigned int	key;
	char			*value;
}	t_parsing;

typedef struct s_dict
{
	unsigned int	maxk;
	t_parsing		*k;
	t_parsing		*u;
}	t_dict;

// k > thousands (key = num of 0 / 3)
// u > below thousands units (key = num)

#endif 
