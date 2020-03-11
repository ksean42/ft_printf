/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:19:21 by ksean             #+#    #+#             */
/*   Updated: 2020/03/11 20:31:07 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ft_strtoupper(char *c)
{
	int i;

	i = 0;
	while(c[i] != '\0')
	{
		if (c[i] >= 97 && c[i] <= 122)
		c[i] -= 32;
		i++;
	}
	return (c);
}

const char	*checker(const char *str, va_list ap, int *res)
{
	char	k;
	char	*s;
	size_t		i;

	if (!str)
		return (NULL);
	if (*str == 'c')
	{
		k = va_arg(ap, int);
		write(1, &k, 1);
		*res += 1;
	}
	if (*str == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr(s);
		*res += ft_strlen(s);
	}
	if (*str == 'd' || *str == 'i' )
	{
		i = va_arg(ap, int);
		s = ft_itoa(i);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}
	if(*str == 'p')
	{
		i = va_arg(ap, size_t);
		s = dec_to_hex(i);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}

	if(*str == 'u')
	{
		i = va_arg(ap, unsigned int);
		s = itoa_base(i, 10);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}

	if(*str == 'o')
	{
		i = va_arg(ap, unsigned int);
		s = itoa_base(i, 8);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}

	if(*str == 'x')
	{
		i = va_arg(ap, unsigned int);
		s = itoa_base(i, 16);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}
	if(*str == 'X')
	{
		i = va_arg(ap, unsigned int);
		s = itoa_base(i, 16);
		s = ft_strtoupper(s);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}
	str++;
	return (str);
}

int	parse(const char *str, va_list ap)
{
	int res;
	int c;

	c = 0;
	res = 0;
	while (*str)
	{
		if (*str == '%')
			{
				str++;
				str = checker(str, ap, &res);
			}
		if(*str != '%')
			{
				write(1, str, 1);
				str++;
				res++;
			}

	}
	return (res + c);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int res;

	va_start(ap, format);
	res = parse(format, ap);
	va_end(ap);
	return (res); // number of printed symbols
}

int	main()
{
	// int a =  -3;
	// int *p = &a;
	// printf("---------------------FT------------------------\n");
	// a = ft_printf("12%s%dkek\n", "PASASI", 999);
	// printf("\n--------------------ORIG-----------------------\n");
	// printf("%p", &a);
	// printf("%p\n" , (void*)0);
	// ft_printf("%p\n" , (void*)0);
	// printf("%d\n" , &a);
	// ft_printf("%X\n" , -532542342);
	ft_printf("%i\n" , 54654);
	// printf("%d\n" , -14234234);
	printf("%li\n" , 5465545454);
	// printf("\n-----------------------------------------------\n");
	// printf("%d\n", a);
	// ft_putstr((void*)p);

	// a = printf ("Characters: %c %c \n", 'a', 65);
	// printf("%d\n", a);
	// a = ft_printf ("Characters: %c %c \n", 'a', 65);
	// printf("%d\n", a);
	// printf ("Decimals: %d %ld\n", 1977, 650000L);
	// printf ("Preceding with blanks: %10d \n", 1977);
	// printf ("Preceding with zeros: %010d \n", 1977);
	// printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	// printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	// printf ("Width trick: %*d \n", 5, 10);
	// printf ("%s \n", "A string");
	return 0;
}




// TODO:
//
//
//
//