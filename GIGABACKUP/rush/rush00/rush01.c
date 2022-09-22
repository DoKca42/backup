/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:52:48 by loculy            #+#    #+#             */
/*   Updated: 2022/09/03 11:31:36 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_charprint(int cursor, char a, char b, int y)
{
	if (cursor == 1)
		ft_putchar(a);
	else if (cursor == y)
		ft_putchar(b);
	else
		ft_putchar('*');
}

void	ft_charslect(int cursor, int line, int y, int x)
{
	if (line == 1)
		ft_charprint(cursor, '/', '\\', y);
	else if (line == y)
		ft_charprint(cursor, '\\', '/', x);
	else if (cursor == 1 || cursor == y)
		ft_putchar('*');
	else
		ft_putchar(' ');
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
			ft_charslect(b, a, y, x);
			b++;
		}
		ft_putchar('\n');
		a++;
	}	
}
