/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:43:39 by loculy            #+#    #+#             */
/*   Updated: 2022/09/06 19:43:46 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_factorial(int nb)
{
	int	res;

	res = 0;
	if (nb < 0)
		return (0);
	else
	{
		while (nb > 0)
		{
			if (res == 0)
				res = nb;
			else
				res = res * nb;
			nb--;
		}
	}
	return (res);
}
