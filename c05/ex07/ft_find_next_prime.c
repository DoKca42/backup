/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:30:01 by loculy            #+#    #+#             */
/*   Updated: 2022/09/07 19:30:03 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	prime;

	i = 2;
	prime = nb;
	if (nb <= 1)
		prime = 0;
	while (i < nb && prime != 0)
	{
		if (nb % i == 0)
			prime = 0;
		i++;
	}
	if (prime == 0)
	{
		nb = nb + 1;
		prime = ft_find_next_prime(nb);
	}
	return (prime);
}
