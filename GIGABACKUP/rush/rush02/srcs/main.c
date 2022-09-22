/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:15:47 by loculy            #+#    #+#             */
/*   Updated: 2022/09/17 19:57:43 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes/parsing.h"

void	ft_list_size(int size, int *uk)
{
	if (size > 3)
		*uk += 1;
	else
		*(uk + 1) += 1;
}

int	parsing_size(int *error)
{
	unsigned int	listesize;
	char			buffer[4096];
	int				fd;

	listesize = 0;
	fd = open("../resources/numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		ft_error_dict(error);
		return (0);
	}
	else
	{
		while (read(fd, buffer, 1))
			listesize++;
		return (listesize);
	}
}

unsigned char	*parsing_convert(int *error)
{
	int				res;
	int				fd;
	unsigned char	*tab;
	char			buffer[4096];

	res = parsing_size(error);
	fd = open("../resources/numbers.dict", O_RDONLY);
	tab = (unsigned char *)malloc((res + 1) * sizeof(unsigned char));
	if (tab == NULL || fd == -1)
	{
		ft_error_dict(error);
		return (NULL);
	}
	else
	{
		res = 0;
		while (read(fd, buffer, 1))
			tab[res++] = buffer[0];
		tab[res] = '\0';
		return (tab);
	}
}

char *ft_valuemalloc(unsigned char *tab, int i)
{
	int		size;
	char 	*m;
	int		o;

	size = i;
	while (tab[i] >= 32 && tab[i] <= 126 && tab[i])
		i++;
	size = i - size;
	m = (char *)malloc((size + 1) * sizeof(char));
	if (m != NULL)
	{
		i -= size;
		o = 0;
		while (tab[i] >= 32 && tab[i] <= 126 && tab[i])
		{
			m[o] = tab[i];
			o++;
			i++;
		}
		m[o] = '\0';
		return (m);
	}
	else
		return (NULL);
}

int	ft_k_sw(int *d, int *linek, t_parsing *k, unsigned char	*tab)
{
	int	i;

	i = d[0];
	k[*linek].key = (i - d[1]) / 3;
	while ((tab[i] == ':' || tab[i] == ' ') && tab[i])
		i++;
	k[*linek].value = ft_valuemalloc(tab, i);
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
	u[*lineu].value = ft_valuemalloc(tab, i);
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
/*
unsigned int	ft_atoi_f(unsigned int res, int i, char *str, int *error)
{
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		*error = 1;
		return (0);
	}
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res *= 10;
			res += str[i] - '0';
		}
		else
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	unsigned int	res;
	int				error;
	t_dict			good;

	error = 0;
	res = 0;
	if (argc == 2)
	{
		//check si argv size = 0 avant
		res = ft_atoi_f(0, 0, argv[1], &error);
		if (res == 1)
		{}
		if (error == 1)
			write(1, "Error\n", 6);
		else
		{
			int value = 21;
			good = parsing_read(&error);
			if (error != 1)
			{
				printf(" - %d - ", good.maxk);
				printf("\n\n%d", good.u[value].key);
				printf(" = %s", good.u[value].value);

				printf("\n\n%d", good.k[1].key);
				printf(" = %s",  good.k[1].value);
			}
		}
	}
	return (0);
}
*/