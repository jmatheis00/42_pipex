/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliama <juliama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:00:23 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/20 13:42:40 by juliama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst2;
	const char	*src2;
	size_t		i;

	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	if (dst == NULL && src2 == NULL)
		return (NULL);
	if (src2 < dst2)
	{
		while (len > 0)
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst2);
}

//copies n bytes from memory area src to memory area dest. 
//The memory areas may overlap
/* void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	counter;

	counter = 0;
	if (!dst && !src)
		return (0);
	if ((size_t)dst - (size_t)src < len)
	{
		counter = len - 1;
		while (counter < len)
		{
			((unsigned char *)dst)[counter] = ((unsigned char *)src)[counter];
			counter--;
		}
	}
	else
	{
		while (counter < len)
		{
			((unsigned char *)dst)[counter] = ((unsigned char *)src)[counter];
			counter++;
		}
	}
	return (dst);
} */

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	ex1[] = "hi pizzapasta";
	char	ex2[] = "hello world";
	void	*z;
	size_t	len;

	len = 1;
	printf("\nmemcpy_ex1_ex2 %s", memcpy(ex2, ex1, len));
	printf("\nmemmove_ex1_ex2 %s", memmove(ex2, ex1, len));
	z = ft_memmove(ex2, ex1, len);
	printf("\nft_memmove_ex1_ex2 %s\n", z);
	return (0);
}
*/