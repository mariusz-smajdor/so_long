/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:43:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/08 10:11:05 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_character(char ch, size_t *p, size_t *e, size_t *c)
{
	if (ch == 'P')
		(*p)++;
	else if (ch == 'E')
		(*e)++;
	else if (ch == 'C')
		(*c)++;
	else if (ch != '0' && ch != '1')
		error("The map contains invalid characters");
}

void	check_characters(char **map)
{
	size_t	players;
	size_t	exits;
	size_t	collectibles;
	short	i;
	short	j;

	players = 0;
	exits = 0;
	collectibles = 0;
	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
			check_character(map[i][j], &players, &exits, &collectibles);
	}
	if (players != 1)
		error("The map has wrong number of players");
	if (exits != 1)
		error("The map has wrong number of exits");
	if (collectibles < 1)
		error("The map has wrong number of collectibles");
}
