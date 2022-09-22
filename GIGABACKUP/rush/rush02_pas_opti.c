/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:52:48 by loculy            #+#    #+#             */
/*   Updated: 2022/09/03 11:13:55 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int longeur, int largeur)
{
	int		a;
	int		b;
	char	value;

	a = 0;
	b = 0;
	while (a < longeur)
	{
		b = 0;
		while (b < largeur)
		{
			if (a == 0)
			{
				if (b == 0 || b == largeur -1)
				{
					value = 'A';
				}
				else
				{
					value = 'B';
				}
			}
			else
			{
				if (a == longeur -1)
				{
					if (b == 0 || b == largeur -1)
					{
						value = 'C';
					}
					else
					{
						value = 'B';
					}
				}
				else
				{
					if (b == 0 || b == largeur -1)
					{
						value = 'B';
					}
					else
					{
						value = ' ';
					}
				}
			}
			ft_putchar(value);
			b++;
		}
		ft_putchar('\n');
		a++;
	}	
}
