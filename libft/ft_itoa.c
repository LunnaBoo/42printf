/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:22:20 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/04 14:35:12 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*lowest_nbr(void);
static char	*putnbr(int nb, char *res, size_t *i);
static int	digits(int n);

char	*ft_itoa(int n)
{
	size_t		i;
	char		*res;
	int			size;

	i = 0;
	if (n == -2147483648)
	{
		res = lowest_nbr();
		if (res == NULL)
			return (NULL);
		return (res);
	}
	size = digits(n);
	res = (char *)malloc(sizeof(char) * size + 1);
	res = putnbr(n, res, &i);
	res[size] = '\0';
	return (res);
}

static char	*lowest_nbr(void)
{
	const char	*intmin;
	size_t		i;
	char		*res;

	intmin = "-2147483648";
	i = 0;
	res = (char *)malloc(sizeof(char) * 11 + 1);
	if (res == NULL)
		return (res);
	while (i < 11)
	{
		res[i] = intmin[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	digits(int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		return (1 + digits(-n));
	}
	else if (n >= 10)
	{
		return (1 + digits(n / 10));
	}
	else
	{
		return (1);
	}
}

static char	*putnbr(int nbr, char *res, size_t *i)
{
	if (nbr < 0)
	{
		res[*i] = '-';
		(*i)++;
		putnbr(-nbr, res, i);
	}
	else if (nbr >= 10)
	{
		putnbr(nbr / 10, res, i);
		res[*i] = (nbr % 10) + '0';
		(*i)++;
	}
	else
	{
		res[*i] = nbr + '0';
		(*i)++;
		return (res);
	}
	return (res);
}
