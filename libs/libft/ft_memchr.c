/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:34:06 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/05 16:13:33 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	size_t			i;

	p_s = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (p_s[i] == (unsigned char) c)
			return ((void *)(p_s + i));
		i++;
	}
	return (NULL);
}
