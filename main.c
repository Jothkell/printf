/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:12:22 by jkellehe          #+#    #+#             */
/*   Updated: 2018/08/27 15:41:37 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 /*
 **is it
 **this
 **this is a comment
 */

#include "printf.h"

int		precision(char *format, va_list ap)
{
	int prec;

	prec = 0;
	while (*format != '.' && *format != '%')
		format--;
	if(*format == '%')
		return (10000);
	prec = (format[1] == '*') ? (va_arg(ap, int)) : (ft_atoi(&format[1]));
	return (prec);
}

int		digit(va_list ap, char *format)//this should convert all to long longs, and handle flags relevant to numbers
{
	long long	holder;
	long long	base;

	if (format[0] != 'd' || !(base = 10))
		base = (format[0] == 'x' || format[0] == 'X') ? (16) : (2);
	base = (format[0] == 'o' || format[0] == 'O') ? (8) : (base);
	if (format[-1] == '%')
		holder = (long long)va_arg(ap, int);
	else if (format[-1] == 'l' && format[-2] == 'l')
		holder = (long long)va_arg(ap, long long);
	else if (format[-1] == 'l')
		holder = (long long)va_arg(ap, long);
	ft_putstr_fd_prec(ft_lltoa_base(holder, base, format), 1, precision(format, ap));
	return(0);
}

int		str(va_list ap, char *format)
{
	char *hold = va_arg(ap, char*);
	ft_putstr_fd_prec(hold, 1, precision(format, ap));
	return(0);
}

int		percent(va_list ap, char *format)
{
	ap += 0;
	write(1, "%", 1);
	return (0);
}

void	assign_functs(int (**p) (va_list ap, char *format))
{
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

}

int		ft_printf(const char * restrict format, ...)
{
	va_list			ap;
	int				(*p[123]) (va_list ap, char *format);
 	int				i;
	int type;
	i = 0;

	assign_functs(p);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if(format[i] == '%')
		{
            while(!IS_TYPE(format[i]))
                i++;
			p[format[i]](ap, (char*)&format[i]);//execute the right function
			i++;
		}
		else 
			write(1, &format[i++], 1);
	}
	va_end(ap);
	return (0);
}

int main()
{
	char	*hey = "dan";
	unsigned long	dude = 42;

	ft_printf("this is a number: %.4ld\n and this guy rox: %.5s\n", dude, hey);
	printf("this is a number: %.4ld\n and this guy rox: %.5s\n", dude, hey);
	return(0);
}
