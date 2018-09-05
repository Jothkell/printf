/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:48:52 by jkellehe          #+#    #+#             */
/*   Updated: 2018/06/28 14:55:47 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	rtn;

	rtn = -1;
	while (src[++rtn])
		;
	i = -1;
	while (dst[++i] && i < size)
		;
	rtn += i;
	if ((int)size - ft_strlen(dst) - 1)
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (rtn);
}
