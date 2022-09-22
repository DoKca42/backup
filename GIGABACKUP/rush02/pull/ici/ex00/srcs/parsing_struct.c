/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:07:57 by loculy            #+#    #+#             */
/*   Updated: 2022/09/18 17:09:50 by mde-vaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_k_sw(int *d, int *linek, t_parsing *k, unsigned char	*tab)
{
	int	i;

	i = d[0];
	k[*linek].key = (i - d[1]) / 3;
	while ((tab[i] == ':' || tab[i] == ' ') && tab[i])
		i++;
	ft_valuemalloc(tab, i, k, linek);
	if (k[*linek].value != NULL)
	{
		*linek += 1;
		while (tab[i] >= 32 && tab[i] <= 126 && tab[i])
			i++;
		return (i + 1);
	}
	else
		return (0);
}

int	ft_u_sw(int *d, int *lineu, t_parsing *u, unsigned char	*tab)
{
	int	i;
	int	b;

	i = d[0];
	b = (i - d[1]);
	i = i - (i - d[1]);
	u[*lineu].key = 0;
	while (i < d[1] + b)
	{
		u[*lineu].key *= 10;
		u[*lineu].key += tab[i] - '0';
		i++;
	}
	while ((tab[i] == ':' || tab[i] == ' ') && tab[i])
		i++;
	ft_valuemalloc(tab, i, u, lineu);
	if (u[*lineu].value != NULL)
	{
		*lineu += 1;
		while (tab[i] >= 32 && tab[i] <= 126 && tab[i])
			i++;
		return (i + 1);
	}
	else
		return (0);
}

struct s_dict	parsing_list_fill(unsigned char *tab, int k, int u, int *error)
{
	int		i;
	int		d[2];
	int		linek;
	int		lineu;
	t_dict	parse;

	parse.k = (struct s_parsing *)malloc(k * sizeof(struct s_parsing));
	parse.u = (struct s_parsing *)malloc(u * sizeof(struct s_parsing));
	linek = 0;
	lineu = 0;
	i = 0;
	while (i < parsing_size(error))
	{
		d[1] = i;
		while (tab[i] >= '0' && tab[i] <= '9' && tab[i])
			i++;
		d[0] = i;
		if ((d[0] - d[1]) > 3)
			i = ft_k_sw(d, &linek, parse.k, tab);
		else
			i = ft_u_sw(d, &lineu, parse.u, tab);
	}
	free(tab);
	return (ft_check_i(i, parse, linek, error));
}

struct s_dict	parsing_read(int *error)
{
	unsigned char	*tab;
	int				i;
	int				a;
	int				uk[2];

	tab = parsing_convert(error);
	i = 0;
	uk[0] = 0;
	uk[1] = 0;
	while (i < parsing_size(error))
	{
		a = i;
		while (tab[i] >= '0' && tab[i] <= '9' && tab[i])
			i++;
		ft_list_size(i - a, &uk[0]);
		ft_check_err(tab, i, error, i - a);
		while ((tab[i] == ':' || tab[i] == ' ') && tab[i])
			i++;
		while (tab[i] >= 32 && tab[i] <= 126 && tab[i])
			i++;
		if (tab[i] != '\n')
			ft_error_dict(error);
		i++;
	}
	return (parsing_list_fill(tab, uk[1], uk[0], error));
}
