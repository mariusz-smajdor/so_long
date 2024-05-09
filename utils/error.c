/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:46:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/09 17:29:21 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char **map, char *msg)
{
	short	i;

	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	if (map && map[0])
	{
		i = -1;
		while (++i, map[i])
			free(map[i]);
		free(map);
	}
	exit(1);
}