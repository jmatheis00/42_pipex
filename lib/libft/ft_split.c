/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:07:01 by jmatheis          #+#    #+#             */
/*   Updated: 2022/07/11 12:48:03 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//counting the words to reserve the storage with malloc
static size_t	wordcounter(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}

//length of substring for every word
//returning the last word with strlen of address of s[start]
//other words using strchr as length of substr
//&s[start] --> whole string beginning with start
//difference from strchr & &s[start]-->string to return/length
static size_t	endsofsubs(char const *s, char c, size_t start)
{
	if (ft_strchr(s + start, c) == NULL)
		return (ft_strlen(&s[start]));
	else
		return (ft_strchr(s + start, c) - &s[start]);
}

//freeing the buffer
static char	**bufferfree(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	return (NULL);
}

//skipping c
//creating substrings in buffer
//adding length to string position
/**
 * @brief Hello dis is a description
 * 
 * @param char s this is the string
 * 
 * @return a fucking value
 */
char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	i;
	size_t	start;

	i = 0;
	start = 0;
	if (s == NULL)
		return (NULL);
	buffer = malloc((wordcounter(s, c) + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	while (s[start] != '\0')
	{
		while (s[start] == c)
			start++;
		if (s[start] == '\0')
			break ;
		buffer[i] = (ft_substr(s, start, endsofsubs(s, c, start)));
		if (buffer[i] == NULL)
			return (bufferfree(buffer));
		i++;
		start += endsofsubs(s, c, start);
	}
	buffer[i] = NULL;
	return (buffer);
}
