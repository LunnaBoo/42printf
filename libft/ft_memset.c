/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:50:01 by luccribe          #+#    #+#             */
/*   Updated: 2025/10/22 17:04:37 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	byte_value;
	size_t			i;

	ptr = (unsigned char *)s;
	byte_value = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		ptr[i] = byte_value;
		i++;
	}
	return (s);
}
