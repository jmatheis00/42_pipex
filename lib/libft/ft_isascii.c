/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliama <juliama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:03:10 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/13 21:40:43 by juliama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

//between 0 and octal 0177 --> 127
/*
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("\n\nISASCII");
	c = 'A';
	printf("\nisascii: %d", isascii (c));
	c = '&';
	printf("\nisascii: %d", isascii (c));
	printf("\nREDONEFUNCTIONS");
	c = 'A';
	printf("\nisascii: %d", ft_isascii (c));
	c = '&';
	printf("\nisascii: %d", ft_isascii (c));
}
*/
//c = 'ñ';
//printf("\nnonascii: %d", isascii (c));
//c = 'ñ';
//printf("\nnonascii: %d", ft_isascii (c));