/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-vaul <mde-vaul@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:28:50 by mde-vaul          #+#    #+#             */
/*   Updated: 2022/09/18 19:30:02 by mde-vaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parsing.h"
#include "input_pars.h"
#include "generate_str.h"

#include <stdio.h>

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
		printf("i = %i\n", i);
		j += get_cent(data, input->nbr[i], &output[j], i == input->size - 1);
		j += get_k(data, input->size - i - 1, &output[j]);
		i++;
	}
	return (output);
}

int	ft_strcpy(char *src, char *dst)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i++] = ' ';
	return (i);
}

int	get_cent(t_dict *data, char *nbr, char *output, int is_last)
{
	int	i;

	i = 0;
	if (nbr[0] != '0' && nbr[0] != 0)
	{
		i = ft_strcpy(data->u[nbr[0] - '0'].value, &output[i]);
		i += ft_strcpy(data->u[28].value, &output[i]);
	}
	if (nbr[1] != '0' && nbr[1] != 0)
	{
		if (nbr[1] == '1')
		{
			i += ft_strcpy(data->u[10 + nbr[2] - '0'].value, &output[i]);
			return (i);
		}
		else
			i = ft_strcpy(data->u[nbr[1] - '0'].value, &output[i]);
	}
	if ((nbr[2] != '0' || is_last && nbr[1] == '0' && nbr[0] == '0')
		&& nbr[2] != 0)
		i = ft_strcpy(data->u[nbr[2] - '0'].value, &output[i]);
	return (i);
}

int	get_k(t_dict *data, int n, char *output)
{
	if (n != 0)
	{
		return (ft_strcpy(data->k[n].value, output));
	}
	return (0);
}
