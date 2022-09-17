/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:15:47 by loculy            #+#    #+#             */
/*   Updated: 2022/09/17 11:15:47 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "parsing.h"

void	parsing_read(int fd)
{
	int i;
	int c;
	char buffer[2];

	i = 0;
	while (c = read(fd, buffer, 1))
	{
		buffer[c] = '\0';
		printf("%d", c);
	}

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
	int				fd;

	error = 0;
	res = 0;
	if (argc == 2)
	{
		//check si argv size = 0 avant
		res = ft_atoi_f(0, 0, argv[1], &error);
		if (error == 1)
			write(1, "Error\n", 6);
		else
		{
			printf("%u\n", res);
			fd = open("numbers.dict", O_RDONLY);
			if (fd != -1)
			{
				parsing_read(fd);
			}
		}
	}
	return (0);
}
