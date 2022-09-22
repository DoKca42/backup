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

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/parsing.h"

//CHECKER LES ERRORS D'OUVERTURE | Dict error en pointer

void	ft_error_dict(int *error)
{
	*error = 1;
	write(1, "Dict Error\n", 11);
}

void	ft_list_size(int size, int *k, int *u)
{
	if (size > 3)
		*k += 1;
	else
		*u += 1;
}

unsigned int	parsing_size(void)
{
	unsigned int	listesize;
	char			buffer[4096];
	int				fd;

	listesize = 0;
	fd = open("../resources/numbers.dict", O_RDONLY);
	while (read(fd, buffer, 1))
		listesize++;
	return (listesize);
}

unsigned char	*parsing_convert(void)
{
	int				res;
	int				fd;
	unsigned char	*tab;
	char			buffer[4096];

	res = parsing_size();
	fd = open("../resources/numbers.dict", O_RDONLY);
	tab = malloc((res + 1) * sizeof(unsigned char));
	res = 0;
	while (read(fd, buffer, 1))
		tab[res++] = buffer[0];
	tab[res] = '\0';
	return (tab);
}

struct s_dict	parsing_list_fill(unsigned char *tab, int k, int u)
{
	unsigned int	i;
	unsigned int	a;
	unsigned int	b;
	int				linek;
	int				lineu;
	t_dict			parse;

	parse.k = malloc(k * sizeof(struct s_parsing));
	parse.u = malloc(u * sizeof(struct s_parsing));
	i = 0;
	linek = 0;
	lineu = 0;
	while (i < parsing_size())
	{
		a = i;
		while (tab[i] >= '0' && tab[i] <= '9' && tab[i])
			i++;
		if ((i - a) > 3)
		{
			parse.k[linek].key = (i - a) / 3;
			printf("%d	K	%d	=	", parse.k[linek].key, linek);
			linek++;
		}
		else
		{
			b = (i - a);
			i = i - (i - a);
			parse.u[lineu].key = 0;
			while (i < a + b)
			{
				parse.u[lineu].key *= 10;
				parse.u[lineu].key += tab[i] - '0';
				i++;
			}
			printf("%d	U	%d	=	", parse.u[lineu].key, lineu);
			lineu++;
		}
		while ((tab[i] == ':' || tab[i] == ' ') && tab[i])
			i++;
		while (tab[i] >= 32 && tab[i] <= 126 && tab[i])
		{
			printf("%c", tab[i]);
			i++;
		}
		printf("\n");
		i++;
	}
	return (parse);
}

struct s_dict	parsing_read(int *error)
{
	unsigned char	*tab;
	unsigned int	i;
	unsigned int	a;
	int				k;
	int				u;

	tab = parsing_convert();
	i = 0;
	k = 0;
	u = 0;
	while (i < parsing_size())
	{
		a = i;
		while (tab[i] >= '0' && tab[i] <= '9' && tab[i])
			i++;
		ft_list_size(i - a, &k, &u);
		while ((tab[i] == ':' || tab[i] == ' ') && tab[i])
			i++;
		while (tab[i] >= 32 && tab[i] <= 126 && tab[i])
			i++;
		if (tab[i] != '\n')
			ft_error_dict(error);
		i++;
	}
	return (parsing_list_fill(tab, k, u));
}

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
			parsing_read(&error);
		}
	}
	return (0);
}
