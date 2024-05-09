/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:50:37 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/09 17:19:50 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->p_pos[0] - 1][game->p_pos[1]] == '1')
		return ;
	game->map[game->p_pos[0] - 1][game->p_pos[1]] = 'P';
	if (game->p_pos[0] == game->e_pos[0] && game->p_pos[1] == game->e_pos[1])
		game->map[game->p_pos[0]][game->p_pos[1]] = 'E';
	else
		game->map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->p_pos[0] -= 1;
	fill_textures(*game);
}

void	move_down(t_game *game)
{
	if (game->map[game->p_pos[0] + 1][game->p_pos[1]] == '1')
		return ;
	game->map[game->p_pos[0] + 1][game->p_pos[1]] = 'P';
	if (game->p_pos[0] == game->e_pos[0] && game->p_pos[1] == game->e_pos[1])
		game->map[game->p_pos[0]][game->p_pos[1]] = 'E';
	else
		game->map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->p_pos[0] += 1;
	fill_textures(*game);
}

void	move_left(t_game *game)
{
	if (game->map[game->p_pos[0]][game->p_pos[1] - 1] == '1')
		return ;
	game->map[game->p_pos[0]][game->p_pos[1] - 1] = 'P';
	if (game->p_pos[0] == game->e_pos[0] && game->p_pos[1] == game->e_pos[1])
		game->map[game->p_pos[0]][game->p_pos[1]] = 'E';
	else
		game->map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->p_pos[1] -= 1;
	fill_textures(*game);
}

void	move_right(t_game *game)
{
	if (game->map[game->p_pos[0]][game->p_pos[1] + 1] == '1')
		return ;
	game->map[game->p_pos[0]][game->p_pos[1] + 1] = 'P';
	if (game->p_pos[0] == game->e_pos[0] && game->p_pos[1] == game->e_pos[1])
		game->map[game->p_pos[0]][game->p_pos[1]] = 'E';
	else
		game->map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->p_pos[1] += 1;
	fill_textures(*game);
}
