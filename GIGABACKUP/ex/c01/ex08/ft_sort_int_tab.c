/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:49:55 by loculy            #+#    #+#             */
/*   Updated: 2022/09/01 19:25:48 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		a;
	int		temp;

	i = 0;
	while (i < size)
	{
		a = 0;
		while (a < (size - 1))
		{
			if (tab[a] > tab[a + 1])
			{
				temp = tab[a];
				tab[a] = tab[a + 1];
				tab[a + 1] = temp;
			}
			a++;
		}
		i++;
	}	
}
