/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaha <bbaha@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 00:46:42 by bbaha             #+#    #+#             */
/*   Updated: 2026/11/19 03:17:21 by bbaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	form(const char *format, va_list args)
{
	int	size;

	size = 0;
	if (*format == 'd' || *format == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (*format == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (*format == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (*format == 'u')
		size += ft_putunbr(va_arg(args, unsigned long));
	else if (*format == 'x')
		size += ft_putnbr_base(va_arg(args, long), "0123456789abcdef");
	else if (*format == 'X')
		size += ft_putnbr_base(va_arg(args, long), "0123456789ABCDEF");
	else if (*format == 'p')
		size += ft_putptr(va_arg(args, void *));
	else if (*format == '%')
		size += write(1, format, 1);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		n;

	size = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			size += form(++format, args);
			format++;
		}
		else
		{
			n = write(1, format, 1);
			if (n < 0)
				return (-1);
			size -= n;
			format++;
		}
	}
	va_end(args);
	return (size);
}
