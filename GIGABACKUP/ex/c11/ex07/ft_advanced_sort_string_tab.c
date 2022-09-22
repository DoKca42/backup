/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:51:45 by loculy            #+#    #+#             */
/*   Updated: 2022/09/22 16:51:45 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		a;
	int		o;
	char	*str;

	i = 0;
	o = 0;
	while (tab[o])
		o++;
	while (tab[i])
	{
		a = 0;
		while (a < o - 1)
		{
			if (cmp(tab[a], tab[a + 1]) > 0)
			{
				str = tab[a];
				tab[a] = tab[a + 1];
				tab[a + 1] = str;
			}
			a++;
		}
		i++;
	}
}
