/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:21:53 by ksean             #+#    #+#             */
/*   Updated: 2020/03/11 20:31:17 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dec_to_hex(size_t a)
{
	int		k;
	int		i;
	char	*dest;

	i = 0;
	dest = (char*)malloc(sizeof(char) * 14);
	while (a >= 16)
	{
		k = a - ((a / 16) * 16);
		a /= 16;
		if (k < 10)
			dest[i] = k + 48;
		else
			dest[i] = k + 87;
		i++;
	}
	dest[i] = (a > 9 ? a + 87 : a + 48);
	dest[i + 1] = 'x';
	dest[i + 2] = '0';
	dest[i + 3] = '\0';
	return (ft_strrev(dest));
}
char	*itoa_base(unsigned int a, unsigned int base)
{
	int		k;
	int		i;
	char	*dest;

	i = 0;
	dest = (char*)malloc(sizeof(char) * 9);
	while (a >= base)
	{
		k = a - ((a / base) * base);
		a /= base;
		if (k < 10)
			dest[i] = k + 48;
		else
			dest[i] = k + 87;
		i++;
	}
	dest[i] = (a > 9 ? a + 87 : a + 48);
	dest[i + 1] = '\0';
	return (ft_strrev(dest));
}

