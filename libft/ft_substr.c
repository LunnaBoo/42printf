/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:01:04 by luccribe          #+#    #+#             */
/*   Updated: 2025/10/25 17:01:07 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	i;
	size_t	true_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		true_len = 0;
	else if (len > ft_strlen(s) - start)
		true_len = ft_strlen(s) - start;
	else
		true_len = len;
	sub_string = (char *)malloc(true_len * sizeof(char) + 1);
	if (sub_string == NULL)
		return (NULL);
	i = 0;
	while (i < true_len)
	{
		sub_string[i] = s[start + i];
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
