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

int	ft_hex(unsigned int number, int i)
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

int	ft_hex_ptr(unsigned long long num)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (num >= 16)
	{
		count += ft_hex_ptr(num / 16);
		count += ft_hex_ptr(num % 16);
	}
	else
	{
		count += write(1, &base[num], 1);
	}
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	adress;
	int					count;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	adress = (unsigned long long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	count += ft_hex_ptr(adress);
	return (count);
}
