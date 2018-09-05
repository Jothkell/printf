/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duparray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 13:27:39 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/08 16:25:00 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_duparr(char **str, char **dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(dest[i] = ft_memalloc(sizeof(char) * (ft_strlen(str[i]) + 1))))
			return (1);
		dest[i] = ft_strdup(str[i]);
		i++;
	}
	return (0);
}
