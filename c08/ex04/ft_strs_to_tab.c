/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:58:33 by loculy            #+#    #+#             */
/*   Updated: 2022/09/13 15:58:33 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_str_len(char *w)
{
	int	i;

	i = 0;
	while (w[i])
		i++;
	return (i);
}

char	*ft_strct(char *w)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_str_len(w) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (w[i])
	{
		str[i] = w[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					a;
	struct s_stock_str	*stock_str;

	stock_str = malloc(sizeof(stock_str) * (ac + 1));
	if (stock_str == NULL)
		return (NULL);
	a = 0;
	while (a < ac)
	{
		stock_str[a].size = ft_str_len(av[a]);
		stock_str[a].str = av[a];
		stock_str[a].copy = ft_strct(av[a]);
		
		printf("%lu | %lu\n", (unsigned long)av[a], (unsigned long)ft_strct(av[a]));
		a++;
	}
	stock_str[a].size = 0;
	stock_str[a].str = 0;
	stock_str[a].copy = 0;
	return (stock_str);
}

int	main(void)
{
	int		i;
	struct s_stock_str	*stock_str;
	char				**strs;

	strs = (char **)malloc(5 * sizeof(strs));
	strs[0] = "Salut";
	strs[1] = "testA testB testC";
	strs[2] = "uuuu";
	strs[3] = "Rhh Rhhh";
	strs[4] = "Ahhhhhhhh";
	stock_str = ft_strs_to_tab(5, strs);
	printf("\n\n");
	i = 0;
	while (i < 5)
	{
		printf("Size : %d\n", stock_str[i].size);
		printf("Str  : %s\n", stock_str[i].str);
		printf("Copy : %s\n", stock_str[i].copy);
		printf("\n");
		i++;
	}
	return (0);
}
