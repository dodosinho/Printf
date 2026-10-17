/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didias-d <didias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 10:09:45 by didias-d          #+#    #+#             */
/*   Updated: 2026/10/17 10:09:45 by didias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_checker(va_list ap, char sign)
{
	int	count;

	count = 0;
	if (sign == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (sign == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (sign == 'd' || sign == 'i')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (sign == 'x')
		count += ft_hex(va_arg(ap, unsigned int), 0);
	else if (sign == 'X')
		count += ft_hex(va_arg(ap, unsigned int), 1);
	else if (sign == '%')
		count += ft_putchar_fd('%', 1);
return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		total_count;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	i = 0;
	total_count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			total_count +=ft_checker(ap, format[i + 1]);
			i++;
		}
		else
			total_count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ap);
	return (total_count);
}

int	main(void)
{
	char *name;

	name = "salut";
	ft_printf("%c, salut %s %% %d %x", 'H', name, 100, 10000000);
	return (1);
}
