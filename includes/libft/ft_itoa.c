/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:22:36 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/06 15:34:54 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	i;

	i = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	num;

	num = n;
	len = ft_numlen(n);
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	*(str + len) = 0;
	while (len--)
	{
		*(str + len) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str) = '-';
	return (str);
}
