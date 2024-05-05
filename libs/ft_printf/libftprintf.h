/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:06:13 by msmajdor          #+#    #+#             */
/*   Updated: 2024/03/25 17:46:53 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *str, ...);
int	print_char(char c);
int	print_string(char *s);
int	print_pointer(uintptr_t p);
int	print_number(int n);
int	print_unsigned_number(unsigned int n);
int	print_hex(unsigned int n, int c);

#endif