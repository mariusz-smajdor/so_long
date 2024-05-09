/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:29:39 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/09 11:50:12 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_textures(t_game game)
{
	short	i;
	short	j;

	i = -1;
	while (++i, game.map[i])
	{
		j = -1;
		while (++j, game.map[i][j])
		{
			if (game.map[i][j] == '0')
				mlx_put_image_to_window(game.mlx, game.win, game.txt.b, j * 50, i * 50);
			if (game.map[i][j] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.txt.w, j * 50, i * 50);
			if (game.map[i][j] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.txt.c, j * 50, i * 50);
			if (game.map[i][j] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.txt.p, j * 50, i * 50);
			if (game.map[i][j] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.txt.e, j * 50, i * 50);
		}
	}
}
