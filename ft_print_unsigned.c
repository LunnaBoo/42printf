/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:33:34 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/18 12:33:48 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts %u

#include "ft_printf.h"
#include "libft/libft.h"

static int	character_count(unsigned int nbr);
static void	putnbr(unsigned int nbr);

int	ft_print_unsigned(va_list *ptr)
{
	unsigned int	nbr;

	nbr = va_arg(*ptr, unsigned int);
	putnbr(nbr);
	return (character_count(nbr));
}

static int	character_count(unsigned int nbr)
{
	if (nbr >= 10)
	{
		return (1 + character_count(nbr / 10));
	}
	else
		return (1);
}

static void	putnbr(unsigned int nbr)
{
	if (nbr >= 10)
	{
		putnbr(nbr / 10);
		ft_putchar_fd((nbr % 10) + '0', 1);
	}
	else
	{
		ft_putchar_fd(nbr + '0', 1);
	}
}
