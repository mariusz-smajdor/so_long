/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_collected.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:38:05 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/10 17:47:27 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_all_collected(char **map)
{
	short	i;
	short	j;

	i = -1;
	while (++i, map[i])
	{
		j = -1;
		while (++j, map[i][j] != '\0')
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (false);
	}
	return (true);
}
