/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:36:51 by msmajdor          #+#    #+#             */
/*   Updated: 2024/04/12 13:19:49 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_datatype(char datatype, va_list args)
{
	if (datatype == 'c')
		return (print_char(va_arg(args, int)));
	if (datatype == 's')
		return (print_string(va_arg(args, char *)));
	if (datatype == 'p')
		return (print_pointer(va_arg(args, uintptr_t)));
	if (datatype == 'd' || datatype == 'i')
		return (print_number(va_arg(args, int)));
	if (datatype == 'u')
		return (print_unsigned_number(va_arg(args, unsigned int)));
	if (datatype == 'x')
		return (print_hex(va_arg(args, unsigned int), 'a'));
	if (datatype == 'X')
		return (print_hex(va_arg(args, unsigned int), 'A'));
	if (datatype == '%')
		return (write(1, "%%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		str_len;
	int		i;

	va_start(args, str);
	str_len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			while (str[i + 1] == ' ')
				i++;
			str_len += check_datatype(str[i++ + 1], args);
		}
		else
		{
			write(1, &str[i], 1);
			str_len++;
		}
	}
	va_end(args);
	return (str_len);
}
