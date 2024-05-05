/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:35:24 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/04 09:29:57 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_list(char **ptr, int i)
{
	while (i-- > 0)
		free(ptr[i]);
	free(ptr);
	return (NULL);
}

static size_t	count_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (ft_strchr(s, c))
	{
		s = ft_strchr(s, c);
		words++;
		while (*s == c)
			s++;
	}
	if (*s != c && *s != '\0')
		words++;
	return (words);
}

static char	**fill_list(char **list, const char *s, char c)
{
	size_t	i;

	i = 0;
	while (ft_strchr(s, c) && s)
	{
		list[i++] = ft_substr(s, 0, ft_strchr(s, c) - s);
		if (!list[i - 1])
			return (free_list(list, i));
		s = ft_strchr(s, c);
		while (*s == c)
			s++;
	}
	if (*s != '\0' && s)
	{
		list[i++] = ft_substr(s, 0, ft_strchr(s, '\0') - s);
		if (!list[i - 1])
			return (free_list(list, i));
	}
	list[i] = NULL;
	return (list);
}

char	**ft_split(const char *s, char c)
{
	char	**list;

	if (!s)
		return (NULL);
	while (*s == c)
		s++;
	list = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!list)
		return (NULL);
	list = fill_list(list, s, c);
	return (list);
}
