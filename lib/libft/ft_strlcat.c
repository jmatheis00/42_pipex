/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 17:17:47 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/19 19:51:07 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	counter2;
	size_t	length_src;
	size_t	length_dst;

	length_src = ft_strlen(src);
	length_dst = ft_strlen(dst);
	counter = 0;
	counter2 = length_dst;
	if (!dstsize)
		return (length_src);
	while (counter < length_src && counter2 < dstsize - 1)
	{
		dst[counter2] = src[counter];
		counter++;
		counter2++;
	}
	if (dstsize > length_dst)
	{
		dst[counter2] = '\0';
		return (length_src + length_dst);
	}
	return (length_src + dstsize);
}

//adding src to the end of dst
//returning source length + dstsize
//if dstsize is bigger than dst length -> returning src + dst length
//(number of bytes needed to store the entire string)
//counter2 must be bigger than counter --> space
