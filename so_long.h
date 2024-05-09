/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:46:12 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/06 18:46:39 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/ft_printf/libftprintf.h"
# include <stdbool.h>

void	error(char *msg);
size_t	map_width(char *s);
size_t	map_height(char **map);

char	**parse_map(char *path);
void	validate_map(char **map);
void	check_characters(char **map);
void	check_shape(char **map);
void	check_border(char **map);
size_t	no_newline_len(char *s);

#endif