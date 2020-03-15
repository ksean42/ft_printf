/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksean <ksean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 16:56:54 by ksean             #+#    #+#             */
/*   Updated: 2020/03/15 18:49:27 by ksean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int a;
	printf("---------------------FT------------------------\n");
	ft_putnbr(ft_printf("%s\n", 0x2dddef9f));
	printf("\n--------------------ORIG-----------------------\n");
	ft_putnbr(printf("%s\n", 0x2dddef9f));

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