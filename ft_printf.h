/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didias-d <didias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:36:55 by didias-d          #+#    #+#             */
/*   Updated: 2026/10/26 10:36:55 by didias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

//printf functions
int		ft_printf(const char *format, ...);
int		ft_checker(va_list ap, char sign);

int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_putnbr_fd(int n, int fd);
int		ft_hex(unsigned int number, int i);
int		ft_putnbrunsigned_fd(unsigned int n, int fd);
int		ft_hex_ptr(unsigned long long num);
int		ft_print_ptr(void *ptr);

#endif
