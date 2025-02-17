/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htopa <htopa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:04:50 by htopa             #+#    #+#             */
/*   Updated: 2024/10/14 12:48:13 by htopa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_formatted(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'd' || *format == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (*format == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (*format == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (*format == '%')
		count = ft_putpercent();
	else if (*format == 'u')
		count = ft_putunsignednbr(va_arg(args, unsigned int));
	else if (*format == 'X')
		count = ft_puthexadecimal(va_arg(args, unsigned int), 'X');
	else if (*format == 'x')
		count = ft_puthexadecimal(va_arg(args, unsigned int), 'x');
	else if (*format == 'p')
		count = ft_putpointer(va_arg(args, void *));
	else if (*format != '\0')
		count = ft_putchar(*format);
	return (count);
}

static int	clean_va(va_list args)
{
	va_end(args);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		check_write;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			check_write = print_formatted(format, args);
			if (*format == '\0')
				format--;
		}
		else
			check_write = ft_putchar(*format);
		if (check_write == -1)
			return (clean_va(args));
		count = count + check_write;
		format++;
	}
	va_end(args);
	return (count);
}
