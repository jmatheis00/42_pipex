/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:03:52 by jmatheis          #+#    #+#             */
/*   Updated: 2022/03/28 14:46:12 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

/*
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	c;
	printf("\n\nISALPHA");
	c = 'A';
	printf("\nUppercase alphabetic: %d", isalpha (c));
	c = 'a';
	printf("\nLowercase alphabetic: %d", isalpha (c));
	c = '1';
	printf("\nnonalphabetic: %d", isalpha (c));
	c = '&';
	printf("\nnonalphabetic: %d\n", isalpha (c));
	printf("\nREDONEFUNCTIONS");
	c = 'A';
	printf("\nUppercase alphabetic: %d", ft_isalpha (c));
	c = 'a';
	printf("\nLowercase alphabetic: %d", ft_isalpha (c));
	c = '1';
	printf("\nnonalphabetic: %d", ft_isalpha (c));
	c = '&';
	printf("\nnonalphabetic: %d\n", ft_isalpha (c));
}
*/