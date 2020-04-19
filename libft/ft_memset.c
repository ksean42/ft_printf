/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:22:44 by ksean             #+#    #+#             */
/*   Updated: 2020/04/18 04:55:06 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*dest;

	if (!b)
		return (NULL);
	dest = b;
	i = 0;
	while (len > 0)
	{
		*dest = c;
		dest++;
		len--;
	}
	return (b);
}
