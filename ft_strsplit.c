/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 11:28:50 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/06 16:29:56 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_it(char const *str, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		k++;
	}
	return (k);
}

static	int		count_words(char const *str, char c)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 && str[i] != c) ||
			(str[i] != c && str[i - 1] == c && i > 0))
			ret++;
		i++;
	}
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(*tab) * (count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < count_words(s, c))
	{
		k = 0;
		if (!(tab[i] = ft_strnew(count_it(&s[j], c) + 1)))
			tab[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			tab[i][k++] = s[j++];
		tab[i][k] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
