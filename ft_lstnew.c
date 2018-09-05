/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:15:23 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/07 14:39:57 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!(res->content = (t_list*)malloc(sizeof(content) * content_size)))
		return (NULL);
	if (content == NULL)
	{
		res->content = NULL;
		res->content_size = 0;
		res->next = NULL;
	}
	else
	{
		res->content = ft_memcpy(res->content, content, content_size);
		res->content_size = content_size;
		res->next = NULL;
	}
	return (res);
}
