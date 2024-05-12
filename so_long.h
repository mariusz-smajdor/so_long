/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:46:12 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/12 17:50:28 by msmajdor         ###   ########.fr       */
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
	void	*m;
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
bool	is_all_collected(char **map);

char	**parse_map(char *path);
void	validate_map(char **map);
void	check_characters(char **map);
void	check_shape(char **map);
void	check_border(char **map);
void	check_way(char **map);
void	start_game(t_game game);
void	fill_textures(t_game mlx);
void	move_player(t_game *game, short row_offset, short col_offset);
int		close_game(t_game *game);

#endif
