/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkellehe <jkellehe@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:24:30 by jkellehe          #+#    #+#             */
/*   Updated: 2018/08/27 15:23:08 by jkellehe         ###   ########.fr       */
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
# define IS_TYPE(x) (x == 's' || x == 'S' || x == 'p' || x == 'd' || x == 'D' || x == 'i' || x == 'o' || x == 'O' || x == 'u' || x == 'U' || x == 'x' || x == 'X' || x == 'c' || x == 'C' || x == 'b')
/*typedef struct s_ap t_ap;

struct					s_ap
{
	va_list ap;
	unsigned int prec;
	unsigned int width;
	uint8_t left;


	};*/

//width, precision, left align. 

void					ft_putstr_fd_prec(char const *s, int fd, int prec);
int						precision(char *format, va_list ap);
char            		*ft_lltoa_base(long long n, long long base, char *format);
void					assign_functs(int (**p) (va_list ap, char *format));
int						digit(va_list ap, char *format);
int						ft_printf(const char * restrict format, ...);

# endif
