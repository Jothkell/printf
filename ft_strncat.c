/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:44:51 by jkellehe          #+#    #+#             */
/*   Updated: 2018/06/28 12:51:26 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
		i++;
	while (j < (int)n && s2[j] != '\0')
	{
		if (s2 == '\0')
			while (j++ < (int)n)
				s1[i++] = '\0';
		s1[i] = (char)ft_memalloc(sizeof(char));
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
