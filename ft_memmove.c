/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:11:03 by jkellehe          #+#    #+#             */
/*   Updated: 2018/06/30 13:01:37 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (d == s)
		return (dst);
	else if (s < d)
	{
		d += (len - 1);
		s += (len - 1);
		while (len--)
			*d-- = *s--;
	}
	else
		while (len--)
			*d++ = *s++;
	return (dst);
}
