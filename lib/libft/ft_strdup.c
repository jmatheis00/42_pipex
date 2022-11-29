/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:30:07 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/19 20:03:02 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*test;
	size_t	len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (s2 == NULL)
		return (NULL);
	test = (char *)ft_memcpy(s2, s1, len);
	return (test);
}

//allocates memory for a copy of s1
//copies s1 and returns a pointer to it
//memcpy copies len bytes from memory area src to dst
//memcpy returns original value of dst