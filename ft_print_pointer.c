/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:32:57 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/18 12:33:06 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts %p

#include "libft/libft.h"
#include "ft_printf.h"

static int	print_output(size_t i, int count, char *buff);

int	ft_print_pointer(va_list *ptr)
{
	unsigned long long	address;
	int					count;
	size_t				i;
	char				buffer[32];
	char				*hex_chars;

	hex_chars = "0123456789abcdef";
	address = (unsigned long long)va_arg(*ptr, void *);
	i = 0;
	if (!address || address == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	count = 2;
	while (address != 0)
	{
		buffer[i] = hex_chars[address % 16];
		address = address / 16;
		i++;
	}
	return (print_output(i, count, buffer));
}

static int	print_output(size_t i, int count, char *buff)
{
	while (i > 0)
	{
		i--;
		write (1, &buff[i], 1);
		count++;
	}
	return (count);
}
