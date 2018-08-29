/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 18:51:31 by jkellehe          #+#    #+#             */
/*   Updated: 2018/08/28 17:24:52 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static  int     count_size(long long n)
{
    size_t      i;

    i = 1;
    while (n /= 2)
        i++;
    return (i);
}

char *ft_pad(char *s, int prec, t_ap *tree)
{
	int i;

	i = 0;
	tree->width -= (tree->width > tree->prec) ? (tree->prec) : (tree->width);
	tree->prec -= (tree->prec > ft_strlen(s)) ? (ft_strlen(s)) : (tree->prec);
    while (tree->width > 0)
    {
		write(1, " ", 1);
        tree->width--;
    }
	while ((tree->prec > 0) && NUMBERS(tree->c))
	{
		write(1, "0", 1);
		tree->prec--;
	}
	ft_putstr_fd(s, 1);
	return (s);
}

void    ft_putstr_fd_prec(char *s, int fd, int prec, t_ap *tree)
{
	int i;

	i = 0;
    if (!s)
        return ;
	if (prec != 10000)
		ft_pad(ft_strsub(s, 0, prec), prec, tree);
	else
		ft_putstr_fd(s, 1);
}

char            *ft_lltoa_base(long long n, long long base, char *format)
{
    char            *str;
    int             len;
    long long	    tmp;
	char			*digits;
	char			*hold;

	digits = "0123456789ABCDEF";
	if (IS_LOWER(format[0]))
		digits = "0123456789abcdef";
    len = count_size(n);
    tmp = n;
    if (n < 0 && ++len)
        tmp = -n;
    if (!(str = ft_strnew(len)))
        return (NULL);
    str[--len] = digits[tmp % base];
    while ((tmp = tmp / base))
        str[--len] = digits[(tmp % base)];
    if (n < 0)
        str[--len] = '-';
	hold = ft_strdup(&str[len]);
	free(str);
    return (hold);
}
