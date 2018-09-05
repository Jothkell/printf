/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:25:38 by jkellehe          #+#    #+#             */
/*   Updated: 2018/07/06 15:50:46 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while ((*alst)->next)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst)->content_size = 0;
		*alst = (*alst)->next;
	}
	del((*alst)->content, (*alst)->content_size);
	(*alst)->content_size = 0;
	ft_memdel((void**)alst);
}
