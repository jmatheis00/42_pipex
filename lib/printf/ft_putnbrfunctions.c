/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrfunctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:25:35 by jmatheis          #+#    #+#             */
/*   Updated: 2022/05/24 16:22:24 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_nbr(char c, int *counter)
{
	write (1, &c, 1);
	(*counter)++;
}

void	ft_putnbr(int n, int *counter)
{
	if (n < 0)
	{
		ft_putchar_nbr('-', counter);
		if (n == -2147483648)
		{
			write(1, "2147483648", 10);
			*counter += 10;
			return ;
		}
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, counter);
		n = n % 10;
	}	
	ft_putchar_nbr(n + 48, counter);
}

void	ft_u_putnbr(int n, int *counter)
{
	unsigned int	i;

	i = 4294967296 + n;
	if (i > 9)
	{
		ft_putnbr(i / 10, counter);
		i = i % 10;
	}	
	ft_putchar_nbr(i + 48, counter);
}

void	ft_p_x_putnbr(unsigned long int ch, int *counter)
{
	char	*base16;

	base16 = "0123456789abcdef";
	if (ch > 15)
	{
		ft_p_x_putnbr(ch / 16, counter);
		ft_p_x_putnbr(ch % 16, counter);
	}
	if (ch < 16)
	{
		ft_putchar_nbr(base16[ch], counter);
	}
}

void	ft_bigx_putnbr(unsigned int ch, int *counter)
{
	char	*base16;

	base16 = "0123456789ABCDEF";
	if (ch > 15)
	{
		ft_bigx_putnbr(ch / 16, counter);
		ft_bigx_putnbr(ch % 16, counter);
	}
	if (ch < 16)
	{
		ft_putchar_nbr(base16[ch], counter);
	}
}
