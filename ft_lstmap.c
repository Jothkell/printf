/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:51:26 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/05 12:58:42 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *iter;

	if (!lst)
		return (NULL);
	res = (t_list*)malloc(sizeof(lst));
	iter = (t_list*)malloc(sizeof(lst));
	res = f(ft_lstnew(lst->content, lst->content_size));
	iter = res;
	lst = lst->next;
	while (lst)
	{
		iter->next = f(ft_lstnew(lst->content, lst->content_size));
		lst = lst->next;
		iter = iter->next;
	}
	return (res);
}
