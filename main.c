/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:12:22 by jkellehe          #+#    #+#             */
/*   Updated: 2018/09/05 13:51:39 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 /*
 **is it
 **this
 **this is a comment
 */

#include "printf.h"

int		precision(char *format, va_list ap, t_ap *tree)
{
	tree->prec = 10000;
	tree->width = 0;
	format--;
	while (*format != '.' && *format != '%' && !isFLAG(*format))
		format--;
	if(!ft_atoi(&format[1]) && !ft_atoi(&format[-1]))
	{
		tree->prec = 10000;
		return (10000);
	}
	format += (isFLAG(format[1])) ? (1) : (0);
	tree->z_pad = (format[1] == '0' && format[0] != '.') ? (1) : (0);
	tree->prec = (format[1] == '*') ? (va_arg(ap, int)) : (tree->prec);
	tree->prec = (format[0] == '.') ? (ft_atoi(&format[1])) : (tree->prec);
	tree->width = (isDIGIT(format[1]) && !tree->dot) ? (ft_atoi(&format[1])) : (tree->width);
	//tree->prec -= (isDIGIT(format[1])) ? (tree->prec) : (0);
	while (isDIGIT(format[-1]) && format[1] != '*')
		format--;
	tree->width = (format[1] == '*') ? (va_arg(ap, int)) : (tree->width);//ft_atoi(&format[0]));
	tree->width = (isDIGIT(*format)) ? (ft_atoi(format)) : (tree->width);
	tree->width -= (tree->hash) ? (2) : (0);
	return (tree->prec);
}

int		digit(va_list ap, char *format, t_ap *tree)//this should convert all to intmax_ts, and handle flags relevant to numbers
{
	intmax_t	holder;
	intmax_t	base;
	uintmax_t tmp = 0;

	if (format[0] != 'd' || !(base = 10))
		base = (format[0] == 'x' || format[0] == 'X') ? (16) : (2);
	base = (format[0] == 'o' || format[0] == 'O') ? (8) : (base);
	if(HH(format))
		holder = (intmax_t)(signed char)va_arg(ap, int);
	else if (format[-1] == 'h')
		holder = (intmax_t)(short)va_arg(ap, int);
	else if (!isID(format[-1]))//format[-1] == '%')
		holder = (intmax_t)va_arg(ap, int);
	else if (format[-1] == 'l' && format[-2] == 'l')
		holder = (intmax_t)va_arg(ap, long long);
	else if (format[-1] == 'l')
		holder = (intmax_t)va_arg(ap, long);
	else if (format[-1] == 'j' && base != 10)
	{
		holder = (uintmax_t)va_arg(ap, uintmax_t);
		holder = (unsigned long long)holder;
	}
	else if (format[-1] == 'j')

		holder = va_arg(ap, intmax_t);
	holder = ((base == 16 || base == 8) && holder < 0 && format[-1] != 'l' && format[-1] != 'j') ? ((unsigned int)holder) : (holder);
    holder = ((base == 16 || base == 8) && HH(format)) ? ((unsigned char)holder) : (holder);
	holder = ((base == 16 || base == 8) && format[-1] == 'h' && !HH(format)) ? ((unsigned char)holder) : (holder);
	holder = ((base == 16 || base == 8) && LL(format)) ? ((unsigned long long)holder) : (holder);
	holder = ((base == 16 || base == 8) && format[-1] == 'l' && !LL(format)) ? ((unsigned long)holder) : (holder);
	holder = ((base == 16 || base == 8) && format[-1] == 'j') ? ((uintmax_t)holder) : (holder);
	//holder = ((base == 10) && format[-1] == 'j') ? ((intmax_t)holder) : (holder);
	tree->zero = (holder == 0) ? (1) : (0);
	if (is_unsign(format))
        ft_putstr_fd_prec(ft_umaxtoa_base(holder, base, tree->c), 1, precision(format, ap, tree), tree);
	else
		ft_putstr_fd_prec(ft_maxtoa_base(holder, base, format), 1, precision(format, ap, tree), tree);
	return(0);
}

int		str(va_list ap, char *format, t_ap *tree)
{
	char *hold;

	if (tree->c[0] == 's')
		hold = va_arg(ap, char*);
	if (tree->c[0] == 'S' || (tree->c[0] == 's' && tree->c[-1] == 'l'))
		hold = va_arg(ap, char*);//got to make wchar_t*
	if (!hold)
		tree->ret += write(1, "(null)", 6);
	else
		ft_putstr_fd_prec(hold, 1, precision(format, ap, tree), tree);
	return(0);
}

int character(va_list ap, char *format, t_ap *tree)
{
	wchar_t c;
	if (tree->c[0] == 'c')
		c = (unsigned char)va_arg(ap, int);
	else if (tree->c[-1] == 'l' || tree->c[0] == 'C')
		c = (unsigned char)va_arg(ap, int);//c = (wchar_t)va_arg(ap, wint_t);
	write(1, &c, 1);
	return (0);

}

int		percent(va_list ap, char *format, t_ap *tree)
{
	ap += 0;
	precision(format, ap, tree);
	tree->width--;
	while(((tree->width) > 0) && !(tree->left))
	{
		tree->ret += (tree->z_pad) ? (write(1, "0", 1)) : (write(1, " ", 1));
		tree->width--;
	}
	write(1, "%", 1);
	tree->ret++;
    while(((tree->width) > 0) && (tree->left))
    {
        tree->ret += (tree->z_pad) ? (write(1, "0", 1)) : (write(1, " ", 1));
        tree->width--;
    }
	return (0);
}

void	assign_functs(int (**p) (va_list ap, char *format, t_ap *tree), t_ap *tree)
{
	//tree->c = (char*)malloc(sizeof(char) * 2);
	tree->fd = 1;
	tree->decimal = 0;
	p['O'] = digit;
	p['o'] = digit;
	p['b'] = digit;
	p['X'] = digit;//can we do p['X', 'x'];
	p['x'] = digit;
	p['l'] = digit;
	p['d'] = digit;
	p['i'] = digit;
	p['s'] = str;
	p['%'] = percent;
	p['f'] = floot;
	p['F'] = floot;
	p['a'] = floot;
	p['A'] = floot;
}

void	flags(char *c, t_ap *tree)
{
	tree->left = (*c == '-') ? (1) : (tree->left);
	tree->l = (*c == 'l') ? (1) : (tree->l);
	tree->ll = (*c == 'l' && c[-1] == 'l') ? (1) : (tree->ll);
	tree->hash = (*c == '#') ? (1) : (tree->hash);
	tree->dot = (*c == '.') ? (1) : (tree->dot);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list			ap;
	int				(*p[123]) (va_list ap, char *format, t_ap *tree);
 	int				i;
	int ihold;
	t_ap			*tree;
	
	if (!(tree = (t_ap*)ft_memalloc(sizeof(t_ap))))
		return (0);
	i = 0;
	tree->ret = 0;
	assign_functs(p, tree);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if(format[i] == '%')
		{
			ihold = i;
			i++;
            while(!IS_TYPE(format[i]) && INPUTS(format[i]) && format[i] != '\0')
                flags((char*)&format[i++], tree);
			tree->ret += (!INPUTS(format[i]) && format[i] != ' ' && format[i] != '\0') ? (write(1, &format[i], 1)) : (0);
			i = (format[i] == '\0' || !INPUTS(format[i])) ? (ihold) : (i);
			tree->c = (char*)&format[i];
			ihold += (i == ihold) ? (1) : (p[format[i]](ap, (char*)&format[i], tree));//execute the right function
			assign_functs(p, tree);
			i++;
		}
		else 
		{
			write(1, &format[i++], 1);
			tree->ret++;
		}
	}
	va_end(ap);
	return (tree->ret);
}
/*
int main()
{
	char	*hey = "whoa";
	unsigned long	dude = 420;
	int ret = 0;
	int ret2 = 0;
	int fort2 = 42;

    double dog = 420.555555;
    double doggy = 420.55555555555555;
	ret = ft_printf("% ");
	//ft_printf("%lx", -4294967296);
	printf("\n");
	ret2 = printf("%");

	//printf("%lx", -4294967296);
	printf("\n");
	printf("%d %d\n", ret, ret2);
	return(0);
}

*/
