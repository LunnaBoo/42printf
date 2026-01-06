/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:32:38 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/18 12:32:46 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts %s

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_print_string(va_list *ptr)
{
	char	*str;

	str = va_arg(*ptr, char *);
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
