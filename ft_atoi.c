/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 10:31:18 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/07 16:25:23 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_iswhitespace(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+')
	{
		i++;
		if (str[i] == '-')
		{
			while (str[i] != '\0')
				i++;
		}
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	int			len;
	int			flag;
	long long	res;

	flag = 1;
	res = 0;
	len = ft_iswhitespace((char*)str);
	if (str[len] == '-')
	{
		flag *= -1;
		len++;
	}
	while ((str[len] >= '0' && str[len] <= '9') && str[len] != '\0')
	{
		res *= 10;
		res += (str[len] - 48);
		len++;
	}
	return (res * flag);
}
