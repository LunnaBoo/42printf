/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:34:00 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/18 12:34:08 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts %x %X

#include "ft_printf.h"
#include "libft/libft.h"

static int	print_output(size_t i, char *buffer, char upper_or_lower);

int	ft_print_hex(va_list *ptr, char upper_or_lower)
{
	char			buffer[20];
	char			*hex_chars;
	size_t			i;
	unsigned int	num;

	hex_chars = "0123456789abcdef";
	num = va_arg(*ptr, unsigned int);
	if (num == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	i = 0;
	while (num != 0)
	{
		buffer[i] = hex_chars[num % 16];
		num = num / 16;
		i++;
	}
	return (print_output(i, buffer, upper_or_lower));
}

static int	print_output(size_t i, char *buffer, char upper_or_lower)
{
	int		count;
	char	current_digit;

	count = 0;
	while (i > 0)
	{
		i--;
		current_digit = buffer[i];
		if (upper_or_lower == 'X')
			current_digit = ft_toupper(buffer[i]);
		write (1, &current_digit, 1);
		count++;
	}
	return (count);
}
