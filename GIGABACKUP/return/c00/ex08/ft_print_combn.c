/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:28:18 by loculy            #+#    #+#             */
/*   Updated: 2022/09/01 12:03:29 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bf_write(int n, int arr[])
{
	char	w;
	int		i;

	i = 0;
	while (i < n)
	{
		w = arr[i] + '0';
		write(1, &w, 1);
		i++;
	}
	if (arr[0] < 10 - n)
	{
		write(1, ", ", 2);
	}
}

void	ft_add_arr(int n, int arr[], int pose)
{
	if (pose == 0)
	{
		arr[pose] = 0;
	}
	else
	{
		arr[pose] = arr[pose - 1] + 1;
	}
	while (arr[pose] < 10)
	{
		if (pose == n - 1)
		{
			ft_bf_write(n, arr);
		}
		else
		{
			ft_add_arr(n, arr, pose +1);
		}
		arr[pose] = arr[pose] + 1;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	ft_add_arr(n, arr, 0);
}
