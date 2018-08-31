/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:12:22 by jkellehe          #+#    #+#             */
/*   Updated: 2018/08/30 21:09:27 by jkellehe         ###   ########.fr       */
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
	tree->prec = 0;
	tree->width = 0;
	format--;
	while (*format != '.' && *format != '%' && *format != '-')
		format--;
	if(*format == '%' && !ft_atoi(&format[1]))
	{
		tree->prec = 10000;
		return (10000);
	}
	format += (format[1] == '-') ? (1) : (0);
	tree->prec = (format[1] == '*') ? (va_arg(ap, int)) : (ft_atoi(&format[1]));
	tree->width = (isDIGIT(format[1])) ? (ft_atoi(&format[1])) : (tree->width);
	tree->prec -= (isDIGIT(format[1])) ? (tree->prec) : (0);
	while (isDIGIT(format[-1]) && format[1] != '*')
		format--;
	tree->width = (format[1] == '*') ? (va_arg(ap, int)) : (tree->width);//ft_atoi(&format[0]));
	tree->width = (isDIGIT(*format)) ? (ft_atoi(format)) : (tree->width);
	return (tree->prec);
}

int		digit(va_list ap, char *format, t_ap *tree)//this should convert all to long longs, and handle flags relevant to numbers
{
	long long	holder;
	long long	base;

	if (format[0] != 'd' || !(base = 10))
		base = (format[0] == 'x' || format[0] == 'X') ? (16) : (2);
	base = (format[0] == 'o' || format[0] == 'O') ? (8) : (base);
	if (!isID(format[-1]))//format[-1] == '%')
		holder = (long long)va_arg(ap, int);
	else if (format[-1] == 'l' && format[-2] == 'l')
		holder = (long long)va_arg(ap, long long);
	else if (format[-1] == 'l')
		holder = (long long)va_arg(ap, long);
	holder = (base == 16 && holder < 0) ? ((unsigned int)holder) : (holder);
	ft_putstr_fd_prec(ft_lltoa_base(holder, base, format), 1, precision(format, ap, tree), tree);
	return(0);
}

int		str(va_list ap, char *format, t_ap *tree)
{
	char *hold = va_arg(ap, char*);
	ft_putstr_fd_prec(hold, 1, precision(format, ap, tree), tree);
	return(0);
}

int		percent(va_list ap, char *format, t_ap *tree)
{
	ap += 0;
	precision(format, ap, tree);
	tree->width--;
	while(((tree->width) > 0) && !(tree->left))
	{
		write(1, " ", 1);
		tree->width--;
		tree->ret++;
	}
	write(1, "%", 1);
	tree->ret++;
    while(((tree->width) > 0) && (tree->left))
    {
        write(1, " ", 1);
        tree->width--;
        tree->ret++;
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
}

int		ft_printf(const char * restrict format, ...)
{
	va_list			ap;
	int				(*p[123]) (va_list ap, char *format, t_ap *tree);
 	int				i;
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
			i++;
            while(!IS_TYPE(format[i]))
                flags((char*)&format[i++], tree);
			tree->c = (char*)&format[i];
			p[format[i]](ap, (char*)&format[i], tree);//execute the right function
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

int main()
{
	char	*hey = "whoa";
	unsigned long	dude = 420;
	int ret = 0;
	int ret2 = 0;
	int fort2 = 42;

    double dog = 420.555555;
    double doggy = 420.55555555555555;
	ret = ft_printf("%10x", fort2);
	printf("\n");
	ret2 = printf("%10x", fort2);
	printf("\n");
	printf("%d %d\n", ret, ret2);
	return(0);
}

