/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:31:47 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/18 12:31:50 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	switch_statement(const char *format, size_t index, va_list *ptr);
static int	print_loop(const char *format, int count, va_list *args);

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	count = print_loop(format, count, &args);
	va_end(args);
	return (count);
}

static int	print_loop(const char *format, int count, va_list *args)
{
	size_t	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				write (1, "%", 1);
				count++;
				break ;
			}
			count = count + switch_statement(format, i - 1, args);
			i++;
		}
		else
		{
			write (1, &format[i], 1);
			count++;
			i++;
		}
	}
	return (count);
}

static int	switch_statement(const char *format, size_t index, va_list *ptr)
{
	if (format[index + 1] == 's')
		return (ft_print_string(ptr));
	else if (format[index + 1] == '%')
	{
		write (1, "%", 1);
		return (1);
	}
	else if (format[index + 1] == 'c')
		return (ft_print_char(ptr));
	else if (format[index + 1] == 'p')
		return (ft_print_pointer(ptr));
	else if (format[index + 1] == 'i' || format[index + 1] == 'd')
		return (ft_print_int(ptr));
	else if (format[index + 1] == 'u')
		return (ft_print_unsigned(ptr));
	else if (format[index + 1] == 'x' || format[index + 1] == 'X')
		return (ft_print_hex(ptr, format[index + 1]));
	else
	{
		write (1, &format[index], 1);
		write (1, &format[index + 1], 1);
		return (2);
	}
}
