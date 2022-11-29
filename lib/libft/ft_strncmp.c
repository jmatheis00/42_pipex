/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:51:44 by jmatheis          #+#    #+#             */
/*   Updated: 2022/10/11 15:21:24 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

//comparing two strings
//if same -> returning NULL
//if one char is different --> returning difference
/*
int	main(void)
{
	char	ex1[] = "test";
	char	ex2[] = "";
	int	z;
	size_t	n;

	n = '4';
	z = ft_strncmp(ex1, ex2, n);
	printf("\nSTRNCMP");
	printf("\nstrncmp: %d", strncmp (ex1, ex2, n));
	printf("\nft_strncmp: %d\n", z);
}
*/