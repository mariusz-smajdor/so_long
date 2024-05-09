/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:20:50 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/09 11:51:04 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_textures(t_game *game)
{
	game->txt.b = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm", &(game->w), &(game->h));
	game->txt.w = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm", &(game->w), &(game->h));
	game->txt.c = mlx_xpm_file_to_image(game->mlx, "textures/c.xpm", &(game->w), &(game->h));
	game->txt.p = mlx_xpm_file_to_image(game->mlx, "textures/p.xpm", &(game->w), &(game->h));
	game->txt.e = mlx_xpm_file_to_image(game->mlx, "textures/e.xpm", &(game->w), &(game->h));
}

void	start_game(t_game game)
{
	game.mlx = mlx_init();
	game.w = map_width(game.map[0]);
	game.h = map_height(game.map);
	game.win = mlx_new_window(game.mlx, game.w * 50, game.h * 50, "so_long");
	init_textures(&game);
	fill_textures(game);
	mlx_loop(game.mlx);
}
