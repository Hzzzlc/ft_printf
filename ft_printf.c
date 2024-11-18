/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcruz-me <hcruz-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:40:53 by marvin            #+#    #+#             */
/*   Updated: 2024/11/07 17:18:10 by hcruz-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	variables(char specifier, va_list args)
{
	int total = 0;

	if (specifier == 'c')
		total += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		total += ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		total += ft_putnbr(va_arg(args, int));
	else if (specifier == 'p')
		total += ft_hexa(va_arg(args, void *));
	else if (specifier == '%')
		total += ft_putchar('%');
	return total;
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int total = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total += variables(*format, args);
		}
		else
			total += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return total;
}
