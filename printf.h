/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:24:30 by jkellehe          #+#    #+#             */
/*   Updated: 2018/08/31 11:04:20 by jkellehe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define IS_UPPER(x) (x >= 'A' && x <= 'Z')
# define IS_LOWER(x) (x >= 'a' && x <= 'z')
# define IS_TYPE(x) (x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D' || x == 'i' || x == 'o' || x == 'O' || x == 'u' || x == 'U' || x == 'x' || x == 'X' || x == 'c' || x == 'C' || x == 'b' || x == 'f' || x == 'F' || x == 'a' || x == 'A' || x == '%')
# define NUMBERS(x) (*x == 'd' || *x == 'D' || *x == 'x' || *x == 'X' || *x == 'b' || *x == 'o' || *x == 'O')
# define FLOATS(x) (*x == 'f' || *x == 'F' || *x =='a' || *x == 'A')
# define isDIGIT(x) (x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' || x == '9')
# define isID(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')
# define HH(x) (x[-1] == 'h' && x[-2] == 'h')
# define LL(x) (x[-1] == 'l' && x[-2] == 'l')

typedef struct s_ap t_ap;

struct					s_ap
{
	int prec;
	int width;
	int ret;
	uint8_t left;
	uint8_t X;
	uint8_t O;
	uint8_t percent;
	uint8_t l;
	uint8_t ll;
	uint8_t fd;
	uint8_t decimal;
	char *c;

};

//width, precision, left align. 
int    bt_putstr_fd(char const *s, int fd);
int						floot(va_list ap, char *format, t_ap *tree);
char					*ft_ftoa_base(double n, long long base, char *format);
void					ft_putstr_fd_prec(char *s, int fd, int prec, t_ap *tree);
int						precision(char *format, va_list ap, t_ap *tree);
char            		*ft_lltoa_base(long long n, long long base, char *format);
void					assign_functs(int (**p) (va_list ap, char *format, t_ap *tree), t_ap *tree);
int						digit(va_list ap, char *format, t_ap *tree);
int						ft_printf(const char * restrict format, ...);
void					flags(char *c, t_ap *tree);
int						decimals(double holder, float base, t_ap *tree);


# endif
