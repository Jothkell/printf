/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:11:03 by jkellehe          #+#    #+#             */
/*   Updated: 2018/06/27 11:37:01 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (n--)
	{
		*d = (unsigned char)*s;
		if (*s == (unsigned char)c)
		{
			d++;
			return (d);
		}
		s++;
		d++;
	}
	return (NULL);
}
