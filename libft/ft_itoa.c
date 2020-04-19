/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 13:10:28 by ksean             #+#    #+#             */
/*   Updated: 2020/04/05 21:49:18 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_sym(__int128_t n)
{
	int len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += 1;
	}
	if (n / 10 == 0)
		len += 1;
	else
	{
		while (n > 0)
		{
			n = n / 10;
			len += 1;
		}
	}
	return (len);
}

char			*ft_itoa(__int128_t n)
{
	char			*dest;
	int				len;
	int				neg;

	neg = 1;
	if (n < 0)
		neg *= -1;
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_count_sym(n);
	if (!(dest = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	n *= neg;
	dest[len] = '\0';
	while (len--)
	{
		dest[len] = ((n % 10) + 48);
		n = (n / 10);
	}
	if (neg == -1)
		dest[0] = '-';
	return (dest);
}
