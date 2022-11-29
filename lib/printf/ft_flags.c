/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:02:17 by jmatheis          #+#    #+#             */
/*   Updated: 2022/05/27 11:23:49 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//c,s,i,d
//u: unsigned decimal (base 10), max_int+1 - negative input, 
//in case of pos no. it stays the same
//x & X: hexadecimal (base 16) lowercase & uppercase format
//p: (pointer -> address) "0x" + no. in hexadecimal

void	flags(va_list	ptr, int *counter, char print)
{
	unsigned int	output;

	if (print == 'u')
	{
		output = va_arg(ptr, unsigned int);
		ft_u_putnbr(output, counter);
	}
	else if (print == 'x')
	{
		output = va_arg(ptr, unsigned int);
		ft_p_x_putnbr(output, counter);
	}
	else if (print == 'X')
	{
		output = va_arg(ptr, unsigned int);
		ft_bigx_putnbr(output, counter);
	}
	else if (print == '%')
	{
		ft_putchar('%');
		(*counter)++;
	}
}

void	flags2(va_list	ptr, int *counter, char print)
{
	char	*output3;
	int		output4;

	if (print == 's')
	{
		output3 = va_arg(ptr, char *);
		ft_putstr(output3, counter);
	}
	else if (print == 'd' || print == 'i')
	{
		output4 = va_arg(ptr, int);
		ft_putnbr(output4, counter);
	}
	else if (print == 'c')
	{
		ft_putchar((char)va_arg(ptr, int));
		(*counter)++;
	}
}

void	flags3(va_list	ptr, int *counter, char print)
{
	unsigned long int	output2;

	if (print == 'p')
	{
		write(1, "0x", 2);
		*counter = *counter + 2;
		output2 = va_arg(ptr, unsigned long int);
		ft_p_x_putnbr(output2, counter);
	}
}

// int counter in printf
// int *counter = &counter -> value of counter
// incrementing *counter --> incrementing val of counter