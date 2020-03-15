/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:19:51 by ksean             #+#    #+#             */
/*   Updated: 2020/03/15 18:41:44 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_flags
{
	int			h;
	int			hh;
	int			l;
	int			ll;
}				t_flags;

typedef struct	s_print
{
	va_list 	ap;
	const char	*str;
	int 		res;
	t_flags 	flag;
}				t_print;

char			*dec_to_hex(unsigned long int a);
char			*itoa_base(unsigned int a, unsigned int base);
char 			*ft_strtoupper(char *c);


int				parse(t_print *data);
const char		*conversions(const char *str, va_list ap, int *res);
int				ft_printf(const char *format, ...);
