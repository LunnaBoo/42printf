/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:08:21 by luccribe          #+#    #+#             */
/*   Updated: 2025/10/25 17:08:24 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cc;
	char	*res;

	res = NULL;
	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
		{
			res = (char *)&s[i];
		}
		i++;
	}
	if (cc == '\0')
	{
		res = (char *)&s[i];
		return (res);
	}
	return (res);
}
