/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 18:51:31 by jkellehe          #+#    #+#             */
/*   Updated: 2018/08/31 10:34:31 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int    bt_putstr_fd(char const *s, int fd)
{
	int ret;

	ret = 0;
    if (!s)
        return (0);
    while (*s != '\0')
    {
        write(fd, s, 1);
        s++;
		ret++;
    }
	return (ret);
}

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
	int hold;
	int widthh;
	int prech;

	i = 0;
	hold = tree->width;
	widthh = 0;
	prech = 0;
	//tree->width -= (tree->width > tree->prec) ? (tree->prec) : (tree->width);
    tree->prec = (tree->prec <= 0) ? (ft_strlen(s)) : (tree->prec);
	tree->width = (!NUMBERS(tree->c)) ? (hold - ft_strlen(s)) : (tree->width - tree->prec);
	tree->prec -= (tree->prec > ft_strlen(s)) ? (ft_strlen(s)) : (tree->prec);
    prech = (tree->prec <= 0) ? (0) : (tree->prec);
    tree->prec = (tree->prec <= 0) ? (ft_strlen(s)) : (tree->prec);
	widthh = tree->width;
	tree->ret += (tree->left) ? (bt_putstr_fd(s, 1)) : (0);
    while (widthh > 0)
    {
		write(1, " ", 1);
        widthh--;
		tree->ret++;
    }
	while ((prech > 0) && NUMBERS(tree->c))
	{
		write(1, "0", 1);
		prech--;
		tree->ret++;
	}
	tree->ret += !(tree->left) ? (bt_putstr_fd(ft_strsub(s, 0, tree->prec), 1)) : (0);
	return (s);
}

void	ft_fpad(char *s, t_ap *tree)
{
	tree->width -= (tree->prec == 10000) ? (ft_strlen(s) + 6) : (ft_strlen(s) + tree->prec + 1);
	tree->width = (tree->width < 0) ? (0) : (tree->width);
	tree->width += (tree->prec == 0) ? (1) : (0);
	while(((tree->width) > 0) && !(tree->decimal))
	{
		write(1, " ", 1);
		tree->width--;
		tree->ret++;
	}
    tree->ret += bt_putstr_fd(s, 1);
	tree->prec -= (tree->decimal) ? (ft_strlen(s)) : (0);
    while ((tree->prec > 0) && tree->decimal)
    {
        write(1, "0", 1);
        tree->prec--;
		tree->ret++;
    }
    tree->decimal = 1;
}

void    ft_putstr_fd_prec(char *s, int fd, int prec, t_ap *tree)
{
	int i;

	i = 0;
    if (!s)
        return ;
	if (prec != 10000 && !FLOATS(tree->c))
		ft_pad(s, prec, tree);
	else if (prec != 10000 && tree->decimal)
		ft_fpad(ft_strsub(s, 0, prec), tree);
	else if (prec != 10000)
		ft_fpad(s, tree);
	else
		tree->ret += bt_putstr_fd(s, 1);
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

char            *ft_ftoa_base(double n, long long base, char *format)
{
    char            *str;
    int             len;
    long long       tmp;
    char            *digits;
    char            *hold;
	int count;

	count = 1;
	n *= 1000000;
    digits = "0123456789ABCDEF";
    if (IS_LOWER(format[0]))
        digits = "0123456789abcdef";
    len = count_size(n);
    tmp = n;
    if (n < 0 && ++len)
        tmp = -n;
    if (!(str = ft_strnew(len + 6)))
        return (NULL);
	len += 6;
    str[--len] = digits[tmp % base];
    while ((tmp = tmp / base) && (count++ >5))
        str[--len] = digits[(tmp % base)];
	str[--len] = '.';
    while ((tmp = tmp / base))
        str[--len] = digits[(tmp % base)];
    if (n < 0)
        str[--len] = '-';
    hold = ft_strdup(&str[len]);
    free(str);
    return (hold);
}

int decimals(double holder, float base, t_ap *tree)
{
	int i = tree->prec;
	int tip = 0;
	float top = 0;

	holder *= (holder < 0) ? (-1) : (1);
	i = (i == 10000) ? (6) : (i);
	tip = (int)holder;
	top = (float)tip;
	holder -= top;
	while (i)
	{
		holder *= base;
		i--;
	}
	tip = (int)holder;
	tip *= (tip < 0) ? (-1) : (1);
	if (((int)(holder * base) % (int)base) >= ((int)base /2))
	{
		tip += 1;
	}
	tree->ret += (tree->prec) ? (write(1, ".", 1)) : (0);
	return (tip);
}

int floot(va_list ap, char *format, t_ap *tree)
{
	double holder;
	float base;
	int temp;//cut out later by placing decimals in next line's call

    if (format[0] == 'f' || format[0] == 'F')//whyd you have to go and make it so complicated
		base = 10;
	else
		base = 16;
    holder = va_arg(ap, double);
	temp = precision(format, ap, tree);
	if((tree->prec == 0) && ((((int)(holder * base) % (int)base) >= ((int)base /2)) ||
							 (((int)(-1 * holder * base) % (int)base) >= ((int)base /2))))
		holder += (holder > 0) ? (1) : (-1);
    ft_putstr_fd_prec(ft_lltoa_base((int)holder, (int)base, format), 1, temp, tree);
	temp = (decimals(holder, base, tree));
	ft_putstr_fd_prec(ft_lltoa_base((int)temp, (int)base, format), 1, tree->prec, tree);
    return(0);
}
