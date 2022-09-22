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

#include <stdlib.h>

int	ft_check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_size_sep(char *str, char *charset)
{
	int		a;
	int		res;

	a = 0;
	res = 0;
	while (str[a])
	{	
		while (ft_check_sep(str[a], charset) && str[a])
			a++;
		if (str[a])
			res += 1;
		while (!ft_check_sep(str[a], charset) && str[a])
			a++;
	}
	return (res);
}

char	*ft_get_word(char *str, char *charset, int *pose)
{
	int		wordlen;
	char	*word;
	int		i;

	wordlen = 0;
	while (ft_check_sep(str[*pose], charset) && str[*pose])
			*pose = *pose + 1;
	while (!ft_check_sep(str[*pose + wordlen], charset) && str[*pose + wordlen])
			wordlen++;
	word = malloc(sizeof(char) * (wordlen + 1));
	i = 0;
	while (i < wordlen)
	{
		word[i++] = str[*pose];
		*pose = *pose + 1;
	}
	word[i++] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**fin;
	int		wordsz;
	int		i;
	int		pose;

	pose = 0;
	wordsz = ft_size_sep(str, charset);
	fin = malloc(sizeof(char *) * (wordsz + 1));
	if (!fin)
		return (0);
	i = 0;
	while (i < wordsz)
		fin[i++] = ft_get_word(str, charset, &pose);
	fin[i] = 0;
	return (fin);
}
