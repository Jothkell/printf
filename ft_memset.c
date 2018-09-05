/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:27:42 by jkellehe          #+#    #+#             */
/*   Updated: 2018/06/23 14:51:53 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*be;

	be = (unsigned char*)b;
	i = -1;
	while (++i < (int)len)
	{
		be[i] = (unsigned char)c;
	}
	return ((void*)be);
}
