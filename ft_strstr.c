/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 21:20:52 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/05 14:56:52 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		rewind;

	rewind = 0;
	j = -1;
	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[++j] != '\0' && ((i = 0) + 1))
		if (haystack[j] == needle[i])
		{
			rewind = 0;
			while (haystack[j] == needle[i])
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
