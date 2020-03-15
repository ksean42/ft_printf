/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:21:53 by ksean             #+#    #+#             */
/*   Updated: 2020/03/15 18:21:22 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int		ft_count_sym(int n)
// {
// 	int len;

// 	len = 0;
// 	if (n < 0)
// 	{
// 		n *= -1;
// 		len += 1;
// 	}
// 	if (n / 10 == 0)
// 		len += 1;
// 	else
// 	{
// 		while (n > 0)
// 		{
// 			n = n / 10;
// 			len += 1;
// 		}
// 	}
// 	return (len);
// }


char	*dec_to_hex(unsigned long int a)
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
		// if (k < 10)
		// 	dest[i] = k + 48;
		// else
		// 	dest[i] = k + 87;
			dest[i] = (k > 9 ? k + 87 : k + 48);
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
	while (a >= base)              // if neg -> unsigned type
	{
		k = a - ((a / base) * base);
		a /= base;
		// if (k < 10)
		// 	dest[i] = k + 48;
		// else
		// 	dest[i] = k + 87;
		dest[i] = (k > 9 ? k + 87 : k + 48);
		i++;
	}
	dest[i] = (a > 9 ? a + 87 : a + 48);
	dest[i + 1] = '\0';
	return (ft_strrev(dest));
}
