/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 18:51:31 by jkellehe          #+#    #+#             */
/*   Updated: 2018/11/19 15:25:21 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void put_wchar(char c)
{
	write(1, &c, 1);

}

int put_wc(wchar_t c)
{
	if (c <= 0x7F)
	{
		put_wchar(c);
		return (1);
	}
	else if (c <= 0x7FF)
	{
		put_wchar((c >> 6) | 0xC0);
		put_wchar((c & 0x3F) | 0x80);
		return (2);
	}
	else if (c <= 0xFFFF)
	{
		put_wchar(((c >> 12) | 0xE0));
		put_wchar(((c >> 6) & 0x3F) | 0x80);
		put_wchar((c & 0x3F) | 0x80);
		return (3);
	}
	else if (c <= 0x10FFFF)
	{
		put_wchar((c >> 18) | 0xF0);
		put_wchar(((c >> 12) & 0x3F) | 0x80);
		put_wchar(((c >> 6) & 0x3F) | 0x80);
		put_wchar((c & 0x3F) | 0x80);
		return (4);
	}
	return (0);
}

int				bt_putstr_fd(char const *s, t_ap *tree)
{
	int			ret;

	tree->ret +=0;
	ret = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		write(tree->fd, s, 1);
		s++;
		ret++;
	}
	return (ret);
}

static int		count_size(intmax_t	n)
{
	size_t		i;

	i = 1;
	while (n /= 2)
		i++;
	return (i);
}
int	bt_putchar(char c, int times)
{
	int		count;

	count = times;
	while (times > 0)
	{
		write(1, &c, 1);
		times--;
	}
	return (count);
}

void			precwidth(int many, t_ap *tree, int prec)
{
	while (many > 0)
	{
		tree->ret += ((tree->z_pad && !tree->left && (tree->prec == 10000))
		|| prec) ? (write(1, "0", 1)) : (write(1, " ", 1));
		many--;
	}
}

int				bt_strlen(const char *s, t_ap *tree, int prec)
{
	int			i;
	int			len;

	len = 0;
	i = 0;
	while (s[i] != '\0')
		len += (s[i++] == '-' && prec) ? (0) : (1);
	len += (tree->plus && !tree->neg && !prec) ? (1) : (0);
	return (len);
}

char			*ft_pad(char *s, t_ap *tree)
{
	tree->prec = ((tree->prec > (int)ft_strlen(s)) && (tree->prec > 0))  ? (tree->prec) : (10000);
	tree->prec -= (tree->prec == 10000) ? (0) : (bt_strlen(s, tree, 1));
	tree->width -= (tree->prec == 10000) ? (bt_strlen(s, tree, 0))
		: (tree->prec + bt_strlen(s, tree, 0));
	tree->width += (!(tree->zero && tree->dot && !tree->z_pad)) ? (0) : (1);
    //tree->width -= (Ox(tree)) ?(2) : (0);
	(!tree->left && !tree->z_pad) ? (precwidth(tree->width, tree, 0)) : (0);
	tree->ret += (Ox(tree) && IS_LOW(tree->c[0])) ? (write(1, "0x", 2)) : (0);
	tree->ret += (Ox(tree) && !IS_LOW(tree->c[0])) ? (write(1, "0X", 2)) : (0);
	tree->ret += (O(tree) && hash(tree)) ? (write(1, "0", 1)) : (0);
	tree->ret += ((tree->plus == 1) && (s[0] != '-') && (plus(tree)))
	? (write(1, "+", 1)) : (0);
	tree->ret += (s[0] == '-') ? (write(1, "-", 1)) : (0);
	s += (s[0] == '-') ? (1) : (0);
	(tree->z_pad && !tree->left) ? (precwidth(tree->width, tree, 0)) : (0);
	(tree->prec != 10000) ? (precwidth(tree->prec, tree, 1)) : (0);
	tree->ret += (SingleSpace(tree)) ? (write(1, " ", 1)) : (0);
	tree->ret += (!((tree->zero && !O(tree) && (tree->prec == 10000)) && tree->dot && !tree->z_pad)) ?
		(bt_putstr_fd(s, tree)) : (0);
	(tree->left) ? (precwidth(tree->width, tree, 0)) : (0);
	//free(s);
	return (NULL);
}

//ft_wpad(s, tree)
char            *ft_wpad(wchar_t *s, t_ap *tree)
{
	tree->len = ft_wstrlen(s);
    tree->prec = (tree->prec > tree->len) ? (tree->len) : (tree->prec);
    tree->width -= (tree->prec == tree->len) ?
        (tree->len) : (tree->len - tree->prec);
    tree->ret += (tree->left && !(tree->zero && tree->dot) && thicc(tree->c)) ?
        (bt_putwstr(s, tree)) : (0);
    while (tree->width > 0)
    {
        tree->ret += (tree->z_pad && !tree->left) ?
            (write(1, "0", 1)) : (write(1, " ", 1));
        tree->width--;
    }
    while (tree->prec != 10000 && (tree->prec > 0) && NUMBERS(tree->c))
    {
        tree->ret += ((tree->c[0] != 'x' && tree->c[0] != 'X') || tree->z_pad) ?
            (write(1, "0", 1)) : (write(1, " ", 1));
        tree->prec--;
    }
    tree->ret += (!tree->left && !(tree->zero && tree->dot) && thicc(tree->c))
        ? (bt_putwstr(s, tree)) : (0);
    return (NULL);
}


char			*ft_spad(char *s, t_ap *tree)
{
	char		*delet;

	tree->prec = (tree->prec > (int)ft_strlen(s)) ? (ft_strlen(s)) : (tree->prec);
    tree->width -= tree->prec;
	delet = ft_strsub(s, 0, tree->prec);
	tree->ret += (tree->left && !(tree->zero && tree->dot)) ?
		(bt_putstr_fd(delet, tree)) : (0);
	while (tree->width > 0)
	{
		tree->ret += (tree->z_pad && !tree->left) ?
			(write(1, "0", 1)) : (write(1, " ", 1));
		tree->width--;
	}
	while (tree->prec != 10000 && (tree->prec > 0) && NUMBERS(tree->c))
	{
		tree->ret += ((tree->c[0] != 'x' && tree->c[0] != 'X') || tree->z_pad) ?
			(write(1, "0", 1)) : (write(1, " ", 1));
		tree->prec--;
	}
	tree->ret += (!tree->left && !(tree->zero && tree->dot))
		? (bt_putstr_fd(delet, tree)) : (0);
	//free(s);
	free(delet);
	return (NULL);
}


int	ft_wstrlen(wchar_t *wc)
{
	int i;
	int len;

	i = -1;
	len = 0;
	while (wc[++i] != 0)
	{
		if (wc[i] <= 0x7F)
			len++;
		else if (wc[i] <= 0x7FF)
			len += 2;
		else if (wc[i] <= 0xFFFF)
			len += 3;
		else if (wc[i] <= 0x10FFFF)
			len += 4;
	}
	return (len);
}



void			ft_putstr_fd_prec(char *s, t_ap *tree)
{
	char *hold;

	if (FLOATS(tree->c))
	{
		ft_pad((hold = ft_strsub(s, 0, tree->prec)), tree);
		free(hold);
		free(s);
	}
	else if (NUMBERS(tree->c))
	{
		ft_pad(s, tree);
		free(s);
	}
	else
		ft_spad(s, tree);
}
/*
void			ft_put_wstr_fd_prec(wchar_t *s, int prec, t_ap *tree)
{
	int			i;

	i = 0;
	if (FLOATS(tree->c))
		i+=1;
	else if (NUMBERS(tree->c))
		i++;
	else
		i++;
		}*/

char			*ft_maxtoa_base(intmax_t n, intmax_t base, char *format)
{
	char		*str;
	int			len;
	intmax_t	tmp;
	char		*digits;
	char		*hold;

	digits = "0123456789ABCDEF";
	if (IS_LOW(format[0]))
		digits = "0123456789abcdef";
	/*if (n == -9223372036854775808 && base == 10)
	  return ("-9223372036854775808");*/
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

char			*ft_umaxtoa_base(uintmax_t n, uintmax_t base, char *format)
{
	char		*str;
	int			len;
	uintmax_t	tmp;
	char		*digits;
	char		*hold;

	digits = "0123456789ABCDEF";
	if (IS_LOW(format[0]))
		digits = "0123456789abcdef";
	len = count_size(n);
	tmp = n;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = digits[tmp % base];
	while ((tmp = tmp / base))
		str[--len] = digits[(tmp % base)];
	hold = ft_strdup(&str[len]);
	free(str);
	return (hold);
}

intmax_t			decimals(double holder, float base, t_ap *tree)
{
	intmax_t		i = tree->prec;
	intmax_t 	tip;
	double 	top;

	holder *= (holder < 0) ? (-1) : (1);
	i = (i == 10000) ? (6) : (i);
	tip = (intmax_t)holder;
	top = (double)tip;
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

void		floot(va_list ap, char *format, t_ap *tree)
{
	long double	holder;
	float	base;
	intmax_t		temp;
	int prec;
	if (format[0] == 'f' || format[0] == 'F')
		base = 10;
	else
		base = 16;
	if (format[-1] == 'L')
		holder = va_arg(ap, long double);
	else
		holder = (long double)va_arg(ap, double);
	prec = precision(format, ap, tree);
	tree->prec = 10000;
	if((tree->prec == 0) && ((((intmax_t)(holder * base) % (intmax_t)base) >= ((intmax_t)base /2)) ||
							 (((intmax_t)(-1 * holder * base) % (intmax_t)base) >= ((intmax_t)base /2))))
		holder += (holder > 0) ? (1) : (-1);
	ft_putstr_fd_prec(ft_maxtoa_base((intmax_t)holder, (intmax_t)base, format), tree);
	tree->prec = prec;
	temp = (decimals(holder, base, tree));
	ft_putstr_fd_prec(ft_maxtoa_base((intmax_t)temp, (intmax_t)base, format), tree);
}
