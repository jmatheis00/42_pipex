/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:56:37 by jmatheis          #+#    #+#             */
/*   Updated: 2022/10/26 12:30:42 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	length;

	counter = 0;
	length = ft_strlen(src);
	if (!src || !dst)
		return (0);
	if (!dstsize)
		return (length);
	while (counter < dstsize && src[counter] != '\0')
	{
		dst[counter] = src[counter];
		counter++;
	}
	if (dstsize <= length)
		dst[dstsize -1] = '\0';
	else if (dstsize != 0)
		dst[counter] = '\0';
	return (length);
}

//copies the string from src to dst (up to dstsize - 1 chars)
//copying src in dest & overwriting content of dst
//if dstsize is smaller/equal to src length -> -1 nullterminating
//returning length of the source
/*
int	main(void)
{
	char	src[] = "12345";
	char	dst[] = "00000";

	printf("source: %s\n", src);
	ft_strlcpy(dst, src, 4);
	printf("ft_strlcpy: %s\n", dst);
	strlcpy(dst, src, 4);
	printf("   strlcpy: %s\n", dst);
	printf("   strlcpy: %zu\n", strlcpy(dst, src, 4));
	printf("   ft_strlcpy: %zu\n", ft_strlcpy(dst, src, 4));
}
*/