/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:06:35 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/20 16:11:09 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int		counter;
	int		numb;

	counter = 0;
	numb = n;
	if (n == 0)
		return (1);
	while (numb != 0)
	{
		numb = numb / 10;
		counter++;
	}
	counter = counter + (n <= 0);
	return (counter);
}

static char	*exist(int n)
{
	char	*newstr;
	int		counter;

	counter = count(n);
	newstr = malloc(sizeof(char) * (counter + 1));
	if (newstr == NULL)
		return (NULL);
	return (newstr);
}

char	*ft_itoa(int n)
{
	char	*newstr;
	int		sign;
	int		counter;

	sign = 1;
	counter = count(n);
	if (n < 0)
		sign = sign * -1;
	newstr = exist(n);
	if (newstr == NULL)
		return (NULL);
	newstr[counter] = '\0';
	while (counter - (sign < 0) > 0)
	{
		counter--;
		newstr[counter] = sign * (char)(n % 10) + '0';
		n = n / 10;
	}
	counter--;
	if (sign < 0)
		newstr[counter] = '-';
	return (newstr);
}

// n = integer to convert to string
// negative numbers must be handled
/* #include <limits.h>
int	main(void)
{
	int	n;

	n = INT_MIN;
	printf("String: %s\n", ft_itoa(n));
} */