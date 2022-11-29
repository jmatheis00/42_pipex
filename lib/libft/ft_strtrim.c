/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:31:21 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/19 18:14:06 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (set == 0 || s1 == 0)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	len = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[len]))
	{
		len--;
	}
	return (ft_substr(s1, 0, len + 1));
}

//finding the first character of set in s1 from beginning
//finding the first character of set in s1 from end
//trims founded characters
//if found --> Length - founded character
//creating a substring from this point
/*
int	main(void)
{
	char s1[] = "lorem ipsum dolor sit amet";
	char *z;
	char *y;

	z = ft_strtrim(s1, "tel");
	y = ft_strtrim(s1, "l ");
	printf("%s\n", z);
	printf("%s\n", y);
}
*/