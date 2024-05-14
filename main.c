/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:47:32 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/11 12:42:45 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		error(NULL, "You must enter only one map file");
	game.map = parse_map(av[1]);
	validate_map(game.map);
	start_game(game);
	free_map(game.map);
	return (0);
}
