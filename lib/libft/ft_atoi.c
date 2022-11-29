/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:46:00 by jmatheis          #+#    #+#             */
/*   Updated: 2022/07/28 18:18:29 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	numb;

	i = 0;
	numb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\t' || str[i] == '\r')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = 10 * numb + (str[i] - 48);
		i++;
	}
	return (numb * sign);
}

//space, newline, tabs, space, carriage return, v = feed
// 48 ascii value of 0
//skipping spaces, skipping sign + multiply it at the end
/*
int	main(void)
{
	char	ex1[] = "546:6";
	char	ex2[] = "+47+5";
	char	ex3[] = "-47-5";
	char	ex4[] = "\t\n\r\v\f  469 \n";
	char	ex5[] = "\n\n\n  -46\b9 \n5d6";

	printf("\natoi: %d", atoi(ex1));
	printf("\nft_atoi: %d\n", ft_atoi(ex1));
	printf("\natoi: %d", atoi(ex2));
	printf("\nft_atoi: %d\n", ft_atoi(ex2));
	printf("\natoi: %d", atoi(ex3));
	printf("\nft_atoi: %d\n", ft_atoi(ex3));
	printf("\natoi: %d", atoi(ex4));
	printf("\nft_atoi: %d\n", ft_atoi(ex4));
	printf("\natoi: %d", atoi(ex5));
	printf("\nft_atoi: %d\n", ft_atoi(ex5));
}
*/