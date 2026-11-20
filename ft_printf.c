/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbaha <bbaha@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 00:46:42 by bbaha             #+#    #+#             */
/*   Updated: 2026/11/20 05:57:39 by bbaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	form(const char *format, va_list args)
{
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (*format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (*format == '\0')
		return (-1);
	else if (*format == '%')
		return (write(1, format, 1));
	else
	{
		if ((write(1, "%", 1) == -1) || (write(1, format, 1) == -1))
			return (-1);
		return (2);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;
	int		n;

	size = 0;
	va_start(args, format);
	n = 0;
	while (*format)
	{
		if (*format == '%')
			n = form(++format, args);
		else
			n = write(1, format, 1);
		if (n == -1)
			break ;
		size += n;
		format++;
	}
	va_end(args);
	if (n == -1)
		return (n);
	return (size);
}
