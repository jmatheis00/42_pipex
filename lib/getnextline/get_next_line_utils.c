/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:34:26 by jmatheis          #+#    #+#             */
/*   Updated: 2022/10/19 16:19:26 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlengnl(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count ++;
	return (count);
}

static char	*ft_strempty(void)
{
	char	*s1;

	s1 = malloc(1);
	if (s1 == NULL)
		return (NULL);
	else
		s1[0] = '\0';
	return (s1);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*concat_str;
	size_t	j;
	size_t	i;

	if (s1 == NULL)
		s1 = ft_strempty();
	if (s2 == NULL)
		return (NULL);
	concat_str = malloc (sizeof(char)
			* (ft_strlengnl(s1) + ft_strlengnl(s2) + 1));
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
		concat_str[i++] = s2[j++];
	concat_str[i] = '\0';
	free (s1);
	return (concat_str);
}

char	*ft_strchrgnl(char *s, int c)
{
	int		length;

	length = 0;
	if (s == NULL)
		return (NULL);
	while (s[length] != (char)c)
	{
		if (s[length] == '\0')
			return (0);
		length++;
	}
	return ((char *)s + length);
}
