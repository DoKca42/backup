/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:05:44 by loculy            #+#    #+#             */
/*   Updated: 2022/09/18 17:06:49 by mde-vaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	fd = open("resources/numbers.dict", O_RDONLY);
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
	fd = open("resources/numbers.dict", O_RDONLY);
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

char	*ft_valuemalloc(unsigned char *tab, int i, t_parsing *p, int *line)
{
	int		size;
	int		o;

	size = i;
	while (tab[i] >= 32 && tab[i] <= 126 && tab[i])
		i++;
	size = i - size;
	p[*line].value = (char *)malloc((500 + 1) * sizeof(char));
	if (p[*line].value != NULL)
	{
		i -= size;
		o = 0;
		while (tab[i] >= 32 && tab[i] <= 126 && tab[i])
		{
			p[*line].value[o] = tab[i];
			o++;
			i++;
		}
		p[*line].value[o] = '\0';
		return (p[*line].value);
	}
	else
		return (NULL);
}
