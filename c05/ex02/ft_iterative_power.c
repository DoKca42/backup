/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:03:15 by loculy            #+#    #+#             */
/*   Updated: 2022/09/06 20:03:18 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 0;
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else
	{
		while (0 < power)
		{
			if (res == 0)
				res = nb;
			else
				res = res * nb;
			power--;
		}
	}
	if (nb < 0)
		res = -res;
	return (res);
}
