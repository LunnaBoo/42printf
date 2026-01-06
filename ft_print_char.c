/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:32:07 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/18 12:32:28 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts %c %%

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_print_char(va_list *ptr)
{
	int	c;

	c = va_arg(*ptr, int);
	ft_putchar_fd(c, 1);
	return (1);
}
