/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:09:41 by jmatheis          #+#    #+#             */
/*   Updated: 2022/10/26 12:30:55 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*test1;
	char	*test2;
	size_t	i;
	size_t	j;

	test1 = (char *) haystack;
	test2 = (char *) needle;
	i = 0;
	j = 0;
	if (!ft_strlen(needle))
		return (test1);
	while (test1[i] != '\0' && i < len)
	{
		while (test1[i + j] == test2[j] && i + j < len)
		{
			j++;
			if (test2[j] == '\0')
				return (test1 + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

//len gives us the part where needle is searched in haystack
//if completely found, return needle + rest of string
//if there is no needle, return the whole haystack string
//if not found return NULL
/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	ex1[] = "aaabcd ipsum dolor sit amet";
	char	ex2[] = "aabc";
	size_t	len;
	char	*z;

	len = 10;
	z = ft_strnstr(ex1, ex2, len);
	printf("\nSTRNSTR");
	printf("\nstrnstr: %s", strnstr (ex1, ex2, len));
	printf("\nft_strnstr: %s\n", z);
} */
