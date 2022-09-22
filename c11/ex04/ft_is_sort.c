/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:55:01 by loculy            #+#    #+#             */
/*   Updated: 2022/09/22 02:11:20 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int c;
	int	d;

	i = 1;
	c = 1;
	d = 1;
	if (length <= 1)
		return (1);
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) > 0)
			c = 0;
	}
	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0)
			d = 0;
	}
	if (c == 1 || d == 1)
		return (1);
	return (0);
}
