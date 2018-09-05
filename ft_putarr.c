/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 14:16:04 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/08 16:12:05 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putarr(char **str)
{
	int	i;
	int	wordct;

	wordct = ft_countwords(str);
	i = 0;
	while (i < wordct)
	{
		ft_putstr(str[i]);
		write(1, "\n", 1);
		i++;
	}
}
