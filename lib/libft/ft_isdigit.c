/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:11:53 by jmatheis          #+#    #+#             */
/*   Updated: 2022/03/28 14:48:54 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	printf("\n\nISDIGIT");
	c = '8';
	printf("\ndigit: %d", isdigit (c));
	c = 'a';
	printf("\nnondigit: %d", isdigit (c));
	printf("\nREDONEFUNCTIONS");
	c = '8';
	printf("\ndigit: %d", ft_isdigit (c));
	c = 'a';
	printf("\nnondigit: %d\n", ft_isdigit (c));
}
*/