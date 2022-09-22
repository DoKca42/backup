/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:29:52 by loculy            #+#    #+#             */
/*   Updated: 2022/09/22 12:29:52 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_argv_com(char *a, char *b)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (a[i] && a[i] == b[i])
		i++;
	res = a[i] - b[i];
	if (res > 0)
		return (1);
	else
		return (0);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_argv_com(tab[a], tab[a + 1]) == 1)
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
