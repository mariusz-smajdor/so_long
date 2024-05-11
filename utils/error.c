/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:46:15 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/11 12:41:43 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(char **map, char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	if (map && map[0])
		free_map(map);
	exit(1);
}
