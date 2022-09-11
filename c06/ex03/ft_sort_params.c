/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:00:54 by loculy            #+#    #+#             */
/*   Updated: 2022/09/08 10:00:56 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_argv_print(char **argv)
{
	int		a;
	int		i;
	char	*str;

	a = 0;
	while (argv[a])
	{
		i = 0;
		str = argv[a];
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		write(1, "\n", 1);
		a++;
	}
}

int	ft_argv_com(char *a, char *b)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (a[i] && a[i] == b[i])
		i++;
	res = a[i] - b[i];
	i = 0;
	if (res > 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		a;
	char	*str;

	i = 1;
	while (argv[i])
	{
		a = 1;
		while (a < argc - 1)
		{
			if (ft_argv_com(argv[a], argv[a + 1]) == 1)
			{
				str = argv[a];
				argv[a] = argv[a + 1];
				argv[a + 1] = str;
			}
			a++;
		}
		i++;
	}
	ft_argv_print(argv);
	return (0);
}
