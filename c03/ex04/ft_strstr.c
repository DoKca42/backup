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

char	*ft_strstr(char *str, char *to_find)
{
	char	*findadd;
	int		a;
	int		b;

	findadd = 0;
	a = 0;
	while (str[a])
	{
		b = 0;
		while (str[a + b] && str[a + b] == to_find[b])
			b++;
		if (to_find[b] == '\0')
			return (&str[a]);
		a++;
	}
	return (findadd);
}
