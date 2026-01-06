/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:33:15 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/18 12:33:22 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts %i %d

#include "ft_printf.h"
#include "libft/libft.h"

static void	putnbr(int nbr);
static int	character_count(int nbr);

int	ft_print_int(va_list *ptr)
{
	int	nbr;

	nbr = va_arg(*ptr, int);
	putnbr(nbr);
	return (character_count(nbr));
}

static void	putnbr(int nbr)
{
	if (nbr == INT_MIN)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write (1, "-", 1);
		putnbr(-nbr);
	}
	else if (nbr >= 10)
	{
		putnbr(nbr / 10);
		ft_putchar_fd((nbr % 10) + '0', 1);
	}
	else
		ft_putchar_fd(nbr + '0', 1);
}

static int	character_count(int nbr)
{
	if (nbr == INT_MIN)
		return (11);
	if (nbr < 0)
		return (1 + character_count(-nbr));
	else if (nbr >= 10)
		return (1 + character_count(nbr / 10));
	else
		return (1);
}
