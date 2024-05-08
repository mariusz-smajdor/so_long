/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:43:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/06 18:54:28 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_character(char c, size_t *players, size_t *exits)
{
	if (c == 'P')
		(*players)++;
	else if (c == 'E')
		(*exits)++;
	else if (c != 'C' && c != '0' && c != '1')
		error("The map contains invalid characters");
}

void	check_characters(char **map)
{
	size_t	players;
	size_t	exits;
	short	i;
	short	j;

	players = 0;
	exits = 0;
	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
			check_character(map[i][j], &players, &exits);
	}
	if (players != 1)
		error("The map has wrong number of players");
	if (exits != 1)
		error("The map has wrong number of exits");
}
