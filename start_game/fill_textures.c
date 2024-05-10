/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:29:39 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/10 16:38:10 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	fill_texture(t_game game, void *txt, short x, short y)
{
	mlx_put_image_to_window(game.mlx, game.win, txt, x, y);
}

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
				fill_texture(game, game.txt.b, j * 50, i * 50);
			if (game.map[i][j] == '1')
				fill_texture(game, game.txt.w, j * 50, i * 50);
			if (game.map[i][j] == 'C')
				fill_texture(game, game.txt.c, j * 50, i * 50);
			if (game.map[i][j] == 'P')
				fill_texture(game, game.txt.p, j * 50, i * 50);
			if (game.map[i][j] == 'E')
				fill_texture(game, game.txt.e, j * 50, i * 50);
		}
	}
}
