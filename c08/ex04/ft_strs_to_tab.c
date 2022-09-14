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

	stock_str = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (stock_str == NULL)
		return (NULL);
	a = 0;
	while (a < ac)
	{
		stock_str[a].size = ft_str_len(av[a]);
		stock_str[a].str = av[a];
		stock_str[a].copy = ft_strct(av[a]);
		a++;
	}
	stock_str[a].size = 0;
	stock_str[a].str = 0;
	stock_str[a].copy = 0;
	return (stock_str);
}
