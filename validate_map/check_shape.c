/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:08:47 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/08 16:25:40 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_shape(char **map)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = map_width(map[i]);
	while (++i, map[i])
		if (map_width(map[i]) != len)
			error("The map must be rectangular!");
}
