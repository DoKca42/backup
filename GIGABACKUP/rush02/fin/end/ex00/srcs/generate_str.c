/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-vaul <mde-vaul@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:28:50 by mde-vaul          #+#    #+#             */
/*   Updated: 2022/09/18 21:11:46 by mde-vaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parsing.h"
#include "input_pars.h"
#include "generate_str.h"

char	*generate_str(t_dict *data, t_parsed_input *input)
{
	unsigned int	i;
	unsigned int	j;
	char			*output;

	i = 0;
	j = 0;
	output = (char *)malloc(sizeof(char) * 12 * data->maxk * 4);
	while (i < 12 * data->maxk * 4)
		output[i++] = 0;
	i = 0;
	while (i < input->size)
	{
		get_cent(data, input->nbr[i], output, i == input->size - 1);
		get_k(data, input->size - i - 1, output);
		i++;
	}
	return (output);
}

void	ft_strcat(char *src, char *dst)
{
	unsigned int	i;

	i = 0;
	while (dst[i])
		i++;
	while (*src)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i++] = ' ';
	dst[i] = 0;
}

void	get_cent(t_dict *data, char *nbr, char *output, int is_last)
{
	if (nbr[0] != '0' && nbr[0] != 0)
	{
		ft_strcat(data->u[nbr[0] - '0'].value, output);
		ft_strcat(data->u[28].value, output);
	}
	if (nbr[1] != '0' && nbr[1] != 0)
	{
		if (nbr[1] == '1')
			ft_strcat(data->u[10 + nbr[2] - '0'].value, output);
		else
			ft_strcat(data->u[nbr[1] - '0' + 18].value, output);
	}
	if ((nbr[2] != '0' || is_last && nbr[1] == '0' && nbr[0] == '0')
		&& nbr[2] != 0)
		ft_strcat(data->u[nbr[2] - '0'].value, output);
}

void	get_k(t_dict *data, int n, char *output)
{
	if (n != 0)
	{
		ft_strcat(data->k[n].value, output);
	}
}
