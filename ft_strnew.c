/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:18:37 by jkellehe          #+#    #+#             */
/*   Updated: 2018/06/28 18:04:05 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	int		i;

	i = 0;
	size++;
	if (!(res = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i < (int)size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
