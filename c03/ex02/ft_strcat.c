/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:35:09 by loculy            #+#    #+#             */
/*   Updated: 2022/09/04 16:35:11 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (dest[a])
		a++;
	while (src[b])
	{
		dest[a + b] = src[b];
		b++;
	}
	dest[a + b] = '\0';
	return (dest);
}
