/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 12:48:45 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/08 16:24:32 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_addstr(char **input, char *addition)
{
	char	**temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(temp = (char**)ft_memalloc(sizeof(char*) * (ft_ctwrds(input) + 2)))
		|| !(temp = input)
		|| !(input = (char**)ft_memalloc(sizeof(char*)
		* (ft_ctwrds(input) + 2))))
		return (NULL);
	while (temp[i] != '\0')
		i++;
	if (!(temp[i] = (char*)ft_memalloc(sizeof(char)
		* (ft_strlen(addition) + 1))))
		return (NULL);
	while (addition[j] != '\0')
	{
		temp[i][j] = addition[j];
		j++;
	}
	input = temp;
	return (input);
}
