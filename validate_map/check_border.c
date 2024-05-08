/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:41:58 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/08 10:41:58 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static bool	is_wall(char *s)
{
	while (s)
	{
		if (*s == '1')
			return (true);
		s++;
	}
	return (false);
}

void	check_border(char **map)
{
	size_t	len;
	short	i;

	i = 0;
	len = no_newline_len(map[i]);
	if (is_wall(map[i]))
		error("The map must be surrounded by walls");
	while (map[i])
    {
		if (map[i][0] == '1' || map[i][len - 1] == '1')
			error("The map must be surrounded by walls");
        i++;
    }
	if (is_wall(map[i - 1]))
		error("The map must be surrounded by walls");
}