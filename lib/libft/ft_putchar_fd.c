/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:49:27 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/06 10:43:52 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// c = charachter to output
// fd: file descriptor on which to write
// no return value
// write function allowed
// outputs the character 'c' to the given file descriptor
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
