/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 11:01:26 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/06 15:17:20 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		*full_blank(void)
{
	char	*res;

	res = ft_memalloc(sizeof(char) * 2);
	return (res);
}

char				*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		stop;
	char	*res;

	j = 0;
	if (s == NULL || (i = 0))
		return (NULL);
	while (s[(i + 1)] != '\0')
		i++;
	while ((s[i] == 32 || s[i] == '\n' || s[i] == '\t') && i >= 0)
		i--;
	if (i == 0 || !(stop = (i + 1)))
		return (full_blank());
	while (s[j] == 32 || s[j] == '\n' || s[j] == '\t' || (i = 0))
		j++;
	if (!(res = (char*)malloc(sizeof(char) * (stop - j + 1))))
		return (NULL);
	while (j < stop)
	{
		res[i] = s[j++];
		i++;
	}
	res[i] = '\0';
	return (res);
}
