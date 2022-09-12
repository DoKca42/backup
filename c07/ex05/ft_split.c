/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:19:39 by loculy            #+#    #+#             */
/*   Updated: 2022/09/12 20:19:39 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	**ft_split(char *str, char *charset)
{
	int		a;
	int		b;
	int		res;
	char	*start;

	a = 0;
	res = 0;
	start = &str[a];
	while (str[a])
	{
		b = 0;
		while (str[a + b] && str[a + b] == charset[b])
			b++;
		if (charset[b] == '\0')
		{
			//printf("%ld -> %ld\n", (long)start, (long)&str[a]);
			while ((long)start < (long)&str[a])
			{
				printf("%c", start[0]);
				start++;
			}
			res += 1;
			printf(" = %d\n", res);
			start = &str[a + b];
		}
		a++;
	}
	printf("\n\n%d", res);
	return (0);
}
