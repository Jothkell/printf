/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 21:20:52 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/05 15:08:08 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		rewind;

	rewind = 0;
	j = -1;
	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (++j < (int)len && haystack[j] != '\0' && ((i = 0) + 1))
		if (haystack[j] == needle[i])
		{
			rewind = 0;
			while (haystack[j] == needle[i] && j < (int)len)
			{
				i++;
				if (needle[i] == '\0')
					return ((char*)&haystack[(j - rewind)]);
				rewind++;
				j++;
			}
			j -= rewind;
		}
	return (NULL);
}
