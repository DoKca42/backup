/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:06:50 by loculy            #+#    #+#             */
/*   Updated: 2022/09/04 17:06:54 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_boolean_find(int a, char *to_find, char *str, char *findadd)
{
	int		b;
	int		c;

	b = 0;
	if (str[a] == to_find[b])
	{
		c = 0;
		findadd = &str[a];
		while (to_find[b])
		{
			if (to_find[b] == str[a + b])
				c++;
			else
				findadd = 0;
			b++;
		}
		if (c == b)
			return (findadd);
	}
	return (findadd);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*findadd;
	int		a;

	findadd = 0;
	a = 0;
	while (str[a])
	{
		findadd = ft_boolean_find(a, to_find, str, findadd);
		if (findadd != 0)
			return (findadd);
		a++;
	}
	return (findadd);
}
