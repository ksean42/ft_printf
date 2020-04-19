/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_csper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 22:01:40 by ksean             #+#    #+#             */
/*   Updated: 2020/04/18 08:25:13 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*s_precision(char *s, t_print *data)
{
	char	*dest;
	int		i;
	int		lens;

	i = 0;
	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (data->precision == 0)
		return (ft_strdup(""));
	if (data->precision == -1)
		return (ft_strdup(s));
	if (!(dest = (char *)malloc(sizeof(char) * (data->precision + 1))))
		return (NULL);
	ft_bzero((void *)dest, data->precision + 1);
	ft_strncat(dest, s, data->precision);
	return (dest);
}

void		manage_percent(t_print *data)
{
	if (data->blank && !data->minus)
		while (--data->blank > 0)
			add_sym(' ', data);
	add_sym('%', data);
	if (data->blank && data->minus)
		while (--data->blank > 0)
			add_sym(' ', data);
}

void		manage_c(t_print *data)
{
	char	k;

	k = va_arg(data->ap, int);
	if (data->blank && !data->minus)
		while (--data->blank > 0)
			add_sym(' ', data);
	add_sym(k, data);
	if (data->blank && data->minus)
		while (--data->blank > 0)
			add_sym(' ', data);
}

void		manage_s(t_print *data)
{
	char	*s;

	if (!(s = va_arg(data->ap, char *)))
	{
		s = s_precision("(null)", data);
		s = add_zero(s, data);
		s = add_blank(s, data);
		add_to_buff(s, data);
		free(s);
		return ;
	}
	s = s_precision(s, data);
	s = add_zero(s, data);
	s = add_blank(s, data);
	add_to_buff(s, data);
	free(s);
}
