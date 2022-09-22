/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:52:48 by loculy            #+#    #+#             */
/*   Updated: 2022/09/03 11:31:36 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_charslect(int cursor, int y, char a, char b)
{
	if (cursor == 1 || cursor == y)
	{
		ft_putchar(a);
	}
	else
	{
		ft_putchar(b);
	}
}

void	rush(int x, int y)
{
	int		a;
	int		b;

	a = 1;
	while (a <= x)
	{
		b = 1;
		while (b <= y)
		{
			if (a == 1)
				ft_charslect(b, y, 'A', 'B');
			else
			{
				if (a == x)
					ft_charslect(b, y, 'C', 'B');
				else
					ft_charslect(b, y, 'B', ' ');
			}			
			b++;
		}
		ft_putchar('\n');
		a++;
	}	
}
