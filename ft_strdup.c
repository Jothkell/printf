/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:16:41 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/06 16:42:53 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;

	i = -1;
	if (!(res = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\0';
	return (res);
}
