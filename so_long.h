/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:46:12 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/10 13:35:15 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/ft_printf/libftprintf.h"
# include "libs/minilibx/mlx.h"
# include <stdbool.h>

typedef struct s_txt
{
	void	*b;
	void	*w;
	void	*c;
	void	*p;
	void	*e;
}	t_txt;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	int		w;
	int		h;
	short	p_pos[2];
	short	e_pos[2];
	t_txt	txt;
}	t_game;

void	error(char **map, char *msg);
void	free_map(char **map);
size_t	map_width(char *s);
size_t	map_height(char **map);
void	find_coords(char **map, short *p_pos, short *e_pos);

char	**parse_map(char *path);
void	validate_map(char **map);
void	check_characters(char **map);
void	check_shape(char **map);
void	check_border(char **map);
void	check_way(char **map);
void	start_game(t_game game);
void	fill_textures(t_game mlx);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);

#endif
