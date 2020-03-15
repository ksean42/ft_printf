/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:19:21 by ksean             #+#    #+#             */
/*   Updated: 2020/03/15 18:44:58 by ksean            ###   ########.fr       */
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


const char	*conversions(const char *str, va_list ap, int *res)
{
	char	k;
	char	*s;
	unsigned long long		i;


	if(*str == '%')
		{
			write(1, "%", 1);
			*res += 1;
		}
	if (*str == 'c')
	{
		k = va_arg(ap, int);
		write(1, &k, 1);
		*res += 1;
	}
	if (*str == 's')
	{
		s = va_arg(ap, char *);
		if(s != NULL && s)
		{
			ft_putstr(s);
			*res += ft_strlen(s);
		}
		else
		{
			ft_putstr("(null)");
			*res += 6;
		}
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
		i = va_arg(ap, unsigned long int);
		s = dec_to_hex(i);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}

	if(*str == 'u')
	{
		i = va_arg(ap, int);
		s = itoa_base(i, 10);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}

	if(*str == 'o')
	{
		i = va_arg(ap,  int);
		s = itoa_base(i, 8);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}

	if(*str == 'x')
	{
		i = va_arg(ap, int);
		s = itoa_base(i, 16);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}
	if(*str == 'X')
	{
		i = va_arg(ap, int);
		s = itoa_base(i, 16);
		s = ft_strtoupper(s);
		ft_putstr(s);
		*res += ft_strlen(s);
		free(s);
	}
	str++;
	return (str);
}


int	parse(t_print *data)
{
	if (data->str == NULL)
	{
		ft_putstr("(null)");
		return (-1);
	}
	data->res = 0;
	while (*data->str)
	{
		if (*data->str == '%')
			{
				data->str++;
				data->str = conversions(data->str, data->ap, &data->res);
			}
		if(*data->str != '%' && *data->str)
			{
				write(1, data->str, 1);
				data->str++;
				data->res++;
			}
	}
	return (data->res);
}

int	ft_printf(const char *format, ...)
{
	t_print *data;
	int res;

	if(!(data = (t_print *)malloc(sizeof(t_print))))
		return(-1);
	ft_bzero((void*)data, sizeof(t_print));
	va_start(data->ap, format);
	data->str = format;
	parse(data);
	va_end(data->ap);
	res = data->res;
	free(data);
	return (res);									// number of printed symbols
}


// TODO:
//
//	%s/ 21 - sega ft/or
// %s/ nothing - sega ft/or !!!!
//	% % does not working
// p with another types???