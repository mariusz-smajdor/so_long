/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:50:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/11 12:41:02 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->txt.b);
	mlx_destroy_image(game->mlx, game->txt.w);
	mlx_destroy_image(game->mlx, game->txt.c);
	mlx_destroy_image(game->mlx, game->txt.p);
	mlx_destroy_image(game->mlx, game->txt.e);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(0);
}

void	move_player(t_game *game, short row_offset, short col_offset)
{
	short	new_row;
	short	new_col;

	new_row = game->p_pos[0] + row_offset;
	new_col = game->p_pos[1] + col_offset;
	if (game->map[new_row][new_col] == '1')
		return ;
	if (game->map)
		game->map[new_row][new_col] = 'P';
	if (new_row == game->e_pos[0] && new_col == game->e_pos[1])
		if (is_all_collected(game->map))
			close_game(game);
	if (game->p_pos[0] == game->e_pos[0] && game->p_pos[1] == game->e_pos[1])
		game->map[game->p_pos[0]][game->p_pos[1]] = 'E';
	else
		game->map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->p_pos[0] = new_row;
	game->p_pos[1] = new_col;
	fill_textures(*game);
}
