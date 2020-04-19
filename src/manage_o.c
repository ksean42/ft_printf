/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:14:10 by ksean             #+#    #+#             */
/*   Updated: 2020/04/18 08:14:42 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_o(char *s)
{
	char *dest;

	if (!s)
		return (NULL);
	if (ft_strcmp(s, "0") == 0)
		return (s);
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2))))
		return (NULL);
	dest[0] = '0';
	dest[1] = '\0';
	dest = ft_strcat(dest, s);
	free(s);
	return (dest);
}

void	manage_o(t_print *data)
{
	long long	i;
	char		*s;

	if (data->type.h == 1)
		i = (unsigned short)va_arg(data->ap, void *);
	else if (data->type.hh == 1)
		i = (unsigned char)va_arg(data->ap, void *);
	else if (data->type.l == 1)
		i = (unsigned long)va_arg(data->ap, void *);
	else if (data->type.ll == 1)
		i = (unsigned long long)va_arg(data->ap, void *);
	else
		i = va_arg(data->ap, unsigned int);
	s = ft_itoa_base(i, 8);
	if (data->octotorp)
		s = add_o(s);
	s = add_zero(s, data);
	if (data->octotorp == 0 || (data->octotorp && data->precision > 0))
		s = add_precision(s, data);
	s = add_blank(s, data);
	add_to_buff(s, data);
	free(s);
}
