/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:31:00 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/19 17:07:27 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat_str;
	size_t	j;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	concat_str = malloc ((ft_strlen (s1) + ft_strlen (s2) + 1) * sizeof(char));
	if (concat_str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[j] != '\0')
	{
		concat_str[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		concat_str[i++] = s2[j++];
	}
	concat_str[i] = '\0';
	return (concat_str);
}

//concatenating two strings (s1 & s2) in a new strings
//reserving the storage with malloc
/*
int	main(void)
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	//char	*strjoin;
	char *z;

	z = ft_strjoin(s1, s2);
	printf("result: %s\n", z);
	return (0);
}
*/