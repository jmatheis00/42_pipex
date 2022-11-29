/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:00:13 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/19 20:09:01 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const	char *s, int c)
{
	int		length;
	char	c2;

	length = 0;
	c2 = (char)c;
	while (s[length] != c2)
	{
		if (s[length] == '\0')
		{
			return (0);
		}
		length++;
	}
	return ((char *)s + length);
}

//searching for a character in s
//if found returning the char + rest of string
//can find null terminator
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	ex1[] = "";
	char	ex2[] = "bonjour";
	char	*z;
	char	*y;
	int	c;

	c = '\0';
	z = ft_strchr(ex1, c);
	y = ft_strchr(ex2, c);
	printf("\n\nSTRCHR");
	printf("\nstrchr_ex1: %s", strchr (ex1, c));
	printf("\nstrchr_ex2: %s", strchr (ex2, c));
	printf("\nft_strchr_ex1: %s", z);
	printf("\nft_strchr_ex2: %s\n", y);
}
*/