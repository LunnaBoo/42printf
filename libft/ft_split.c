/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 19:28:50 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/04 14:35:36 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*string_malloc(size_t length);
static char	**string_return(char **res);
static char	**actual_split(char const *s, char c, char **res);
static char	*string_copy(size_t start, size_t end,
				char const *s, char *current_string);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**res;
	int		count;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (res == NULL)
		return (NULL);
	return (actual_split(s, c, res));
}

static char	**actual_split(char const *s, char c, char **res)
{
	size_t	i;
	size_t	start_index;
	size_t	end_index;
	char	*current_string;

	i = 0;
	end_index = 0;
	while (s[end_index])
	{
		while (s[end_index] == c)
			end_index++;
		if (s[end_index] == '\0')
			break ;
		start_index = end_index;
		while (s[end_index] != c && s[end_index] != '\0')
			end_index++;
		current_string = string_malloc(end_index - start_index);
		if (current_string == NULL)
			return (string_return(res));
		res[i] = string_copy(start_index, end_index, s, current_string);
		i++;
	}
	res[i] = NULL;
	return (res);
}

static char	**string_return(char **res)
{
	size_t	i;

	if (res == NULL)
		return (NULL);
	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		res[i] = NULL;
		i++;
	}
	free(res);
	return (NULL);
}

static char	*string_malloc(size_t length)
{
	char	*current_string;

	current_string = (char *)malloc(sizeof(char) * (length + 1));
	if (current_string == NULL)
		return (NULL);
	return (current_string);
}

static char	*string_copy(size_t start, size_t end,
		char const *s, char *current_string)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		current_string[i] = s[start];
		start++;
		i++;
	}
	current_string[i] = '\0';
	return (current_string);
}
