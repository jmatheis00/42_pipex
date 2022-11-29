/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:14:23 by jmatheis          #+#    #+#             */
/*   Updated: 2022/05/27 11:11:33 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *print, ...)
{
	va_list	ptr;
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	va_start(ptr, print);
	while (print[i] != '\0')
	{
		if (print[i] == '%')
		{
			i++;
			flags(ptr, &counter, print[i]);
			flags2(ptr, &counter, print[i]);
			flags3(ptr, &counter, print[i]);
		}
		else
		{
			ft_putchar(print[i]);
			counter++;
		}
		i++;
	}
	va_end(ptr);
	return (counter);
}

/* 
#include <stdio.h>
int main(void)
{
	// char z[] = "hello";
	char c = 'a';
	// int d = 456;
	// int i = -135654;
	// int output1;
	// int output2;
	// int *p = &i;
	// unsigned int u = -59;
	// ft_printf("%x\n", 3735929054u);
	// printf("%x\n", 3735929054u);
	// ft_printf( "hello %p\n", p);
	// output1=ft_printf("%x\n", 3735929054u);
	// printf( "ft_printf counter %d\n", output1);
	// printf( "hello %p\n", p);
	// output2=printf("%x\n", 3735929054u);
	// printf( "printf counter %d\n", output2);
	// ft_printf( "hello %d\n", d);
	// printf( "hello %d\n", d);
	// ft_printf( "hello %i\n", i);
	// printf( "hello %i\n", i);
	// ft_printf( "hello %u\n", u);
	// printf( "hello %u\n", u);
	// ft_printf( "hello %p\n", p);
	// printf( "hello %p\n", p);
	// ft_printf( "hello %c %s\n", c, z);
	printf( "hello %c\n", c);
	ft_printf( "hello %c\n", c);
	// printf( "hello %s\n", z);
	return (0);
} */