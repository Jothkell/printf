/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 21:13:57 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/07 16:18:59 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;

	if (!(temp = (char*)ft_memalloc(sizeof(s))))
		return (NULL);
	temp = (char*)s;
	while (*s != '\0')
		s++;
	while ((char*)s != temp)
	{
		if (*s == c)
			return ((char*)s);
		s--;
	}
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
