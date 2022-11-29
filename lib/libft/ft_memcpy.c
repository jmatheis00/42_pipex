/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliama <juliama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:04:28 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/20 13:39:23 by juliama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst2;
	const char	*src2;
	size_t		i;

	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	if (dst2 == NULL && src2 == NULL)
		return (NULL);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst2);
}

//copies n bytes from memory area src to memory area dst
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	ex1[] = "hello world";
	char	ex2[] = "bonjour";
	void	*z;
	size_t	n;

	n = 8;
	printf("\nmemcpy_ex1_ex2 %s", memcpy(ex2, ex1, n));
	z = ft_memcpy(ex2, ex1, n);
	printf("\nft_memcpy_ex1_ex2 %s", z);
	return (0);
}

//memmove overlaps (copies source to buffer and moves this to the dest) 
//--> save to use when overlapping
//memcpy doesn't use a buffer
*/