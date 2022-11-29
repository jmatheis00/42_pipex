/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:25:27 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/06 12:40:28 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*test1;
	unsigned char	*test2;
	size_t			i;

	test1 = (unsigned char *) s1;
	test2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (test1[i] != test2[i])
		{
			return (test1[i] - test2[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	ex1[] = "abcdefghij";
	char	ex2[] = "abcdefgxyz";
	int	z;
	size_t	n;

	n = 0;
	z = ft_memcmp(ex1, ex2, n);
	printf("\nMEMCMP");
	printf("\nmemcmp: %d", memcmp (ex1, ex2, n));
	printf("\nmemcmp: %d\n", z);
}
*/