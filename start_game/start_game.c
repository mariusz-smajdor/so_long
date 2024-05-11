/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:20:50 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/09 17:03:24 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_textures(t_game *game)
{
	game->txt.b = mlx_xpm_file_to_image(game->mlx,
			"textures/0.xpm", &(game->w), &(game->h));
	game->txt.w = mlx_xpm_file_to_image(game->mlx,
			"textures/1.xpm", &(game->w), &(game->h));
	game->txt.c = mlx_xpm_file_to_image(game->mlx,
			"textures/c.xpm", &(game->w), &(game->h));
	game->txt.p = mlx_xpm_file_to_image(game->mlx,
			"textures/p.xpm", &(game->w), &(game->h));
	game->txt.e = mlx_xpm_file_to_image(game->mlx,
			"textures/e.xpm", &(game->w), &(game->h));
}

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

int	handle_key_events(int keycode, t_game *game)
{
	if (keycode == 119)
		move_up(game);
	if (keycode == 115)
		move_down(game);
	if (keycode == 97)
		move_left(game);
	if (keycode == 100)
		move_right(game);
	return (0);
}

void	start_game(t_game game)
{
	game.mlx = mlx_init();
	game.w = map_width(game.map[0]);
	game.h = map_height(game.map);
	game.win = mlx_new_window(game.mlx, game.w * 50, game.h * 50, "so_long");
	find_coords(&game);
	init_textures(&game);
	fill_textures(game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, handle_key_events, &game);
	mlx_loop(game.mlx);
}
