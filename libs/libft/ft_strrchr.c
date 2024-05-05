/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:10:45 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/05 15:14:33 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + s_len));
	while (s_len--)
		if (*(s + s_len) == (char) c)
			return ((char *)(s + s_len));
	return (NULL);
}
