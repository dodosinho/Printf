/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didias-d <didias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:15:24 by didias-d          #+#    #+#             */
/*   Updated: 2026/10/17 14:15:24 by didias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return (0);
	write (fd, s, ft_strlen(s));
	return (ft_strlen(s));
}

int ft_putnbr_fd(int n, int fd)
{
    int count;

    count = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10) + '0', fd);
    return (count);
}

int ft_hex(unsigned int  number, int i)
{
	char	*base0;
	char	*base1;
	int		count;

	count = 0;
	base0 = "0123456789abcdef";
	base1 = "0123456789ABCDEF";
	if (number >= 16)
		count += ft_hex(number / 16, i);
	if (i == 0)
		ft_putchar_fd(base0[number % 16], 1);
	else
		ft_putchar_fd(base1[number % 16], 1);
	count++;
	return (count);
}
