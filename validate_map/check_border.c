/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:41:58 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/08 16:33:55 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_border(char **map)
{
	size_t	width;
	size_t	height;
	short	i;
	short	j;

	width = map_width(map[0]) - 1;
	height = map_height(map) - 1;
	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j])
			if (i == 0 || i == height || j == 0 || j == width)
				if (map[i][j] != '1')
					error("The map must be surrounded by walls");
	}
}
