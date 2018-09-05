/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 16:27:36 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/08 16:42:10 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intdup(int *src, int len)
{
	int		*dst;
	int		i;

	dst = (int*)malloc(sizeof(int) * len);
	while (i < len)
	{
		dst[i] = src[i];
	}
	return (dst);
}
