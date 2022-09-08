/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:12:46 by loculy            #+#    #+#             */
/*   Updated: 2022/09/08 19:12:48 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *ft_range(int min, int max)
{
	int	i;
	int *m;

	i = 0;
	while ((min + i) < max)
		i++;
	m = (int *)malloc(sizeof(int) * i);
	i = 0;
	while ((min + i) < max)
	{
		i++;
	}

	return (0);
}
