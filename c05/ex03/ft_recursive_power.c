/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:27:07 by loculy            #+#    #+#             */
/*   Updated: 2022/09/06 20:27:09 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recu_pow(int res, int nb, int power)
{
	if (0 < power)
	{
		if (res == 0)
				res = nb;
		else
			res = res * nb;
		power--;
		res = ft_recu_pow(res, nb, power);
	}
	return (res);
}

int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = 0;
	if (power < 0)
		return (0);
	else if (power < 1)
		return (1);
	else
		res = ft_recu_pow(res, nb, power);
	if (0 > nb)
		res = -res;
	return (res);
}
