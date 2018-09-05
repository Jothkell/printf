/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:11:03 by jkellehe          #+#    #+#             */
/*   Updated: 2018/06/23 17:47:56 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*res;
	unsigned char	*source;

	res = (unsigned char*)dst;
	source = (unsigned char*)src;
	i = -1;
	while (++i < (int)n)
	{
		res[i] = (unsigned char)source[i];
	}
	dst = (void*)res;
	return (dst);
}
