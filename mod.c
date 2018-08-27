/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 18:51:31 by jkellehe          #+#    #+#             */
/*   Updated: 2018/08/27 15:39:07 by jkellehe         ###   ########.fr       */
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

char *ft_pad(char *s, int prec)
{
	int i;

	i = 0;
	prec -= ft_strlen(s);
	while (prec)
	{
		s--;
		*s = '0';
		prec--;
	}
	return (s);
}

void    ft_putstr_fd_prec(char const *s, int fd, int prec)
{
	int i;

	i = 0;
    if (!s)
        return ;
	if (prec != 10000)
		ft_putstr_fd(ft_pad(ft_strsub(s, 0, prec), prec), fd);
	else
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

char            *ft_lltoa_base(long long n, long long base, char *format)
{
    char            *str;
    int             len;
    long long	    tmp;
	char			*digits;
	char		*hold;

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
