/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:51:40 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/19 18:24:01 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*substr;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	substr = (char *)malloc(sizeof (char) * ft_strlen (s) + 1);
	if (substr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		substr[i] = f(i, s[i]);
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// applies the function f to each character of the string 's'
// & passing its index as first argument to create a new string (with malloc)
//s = string on which to iterate
// f = the function to apply to each character
//return: the string created from the successive applications of 'f'