/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:46:26 by jmatheis          #+#    #+#             */
/*   Updated: 2022/05/24 12:14:44 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *print, ...);
void	flags(va_list	ptr, int *counter, char print);
void	flags2(va_list	ptr, int *counter, char print);
void	flags3(va_list	ptr, int *counter, char print);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *s, int *counter);
void	ft_putchar_nbr(char c, int *counter);
void	ft_putnbr(int n, int *counter);
void	ft_u_putnbr(int n, int *counter);
void	ft_p_x_putnbr(unsigned long int ch, int *counter);
void	ft_bigx_putnbr(unsigned int ch, int *counter);
void	ft_putchar(char c);

#endif
