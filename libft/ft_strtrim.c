/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:14:53 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/04 14:34:13 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*string_malloc(char const *s1, size_t start, size_t end);
static int	true_or_false(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (true_or_false(set, s1[start]) == 1 && s1[start] != '\0')
		start++;
	while (true_or_false(set, s1[end - 1]) == 1 && end > start)
		end--;
	return (string_malloc(s1, start, end));
}

static int	true_or_false(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*string_malloc(char const *s1, size_t start, size_t end)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (end - start + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
