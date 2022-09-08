/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loculy <loculy@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:01:40 by loculy            #+#    #+#             */
/*   Updated: 2022/09/04 17:01:44 by loculy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				a;
	unsigned int	b;

	a = 0;
	b = 0;
	while (dest[a])
		a++;
	while (src[b] && b < nb)
	{
		dest[a + b] = src[b];
		b++;
	}
	dest[a + b] = '\0';
	return (dest);
}
