/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 21:41:04 by loculy            #+#    #+#             */
/*   Updated: 2022/09/21 21:41:04 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	c;
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
		i++;
	}
	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0)
			d = 0;
		i++;
	}
	if (c == 1 || d == 1)
		return (1);
	return (0);
}
