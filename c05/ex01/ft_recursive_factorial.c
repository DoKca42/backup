/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:29:41 by loculy            #+#    #+#             */
/*   Updated: 2022/09/06 20:36:45 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recu_fact(int nb, int res)
{

	return (res);
}

int ft_recursive_factorial(int nb)
{
	int	res;

	res = 0;
	if (nb < 0)
		return (0);
	return (ft_recu_fact(nb, res));
}
