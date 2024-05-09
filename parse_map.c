/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:56:04 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/09 17:31:17 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_map(int fd)
{
	char	*str;
	char	*tmp;
	char	*line;

	str = get_next_line(fd);
	if (!str)
		error(NULL, "Map file is empty");
	line = get_next_line(fd);
	while (line)
	{
		tmp = str;
		str = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	return (str);
}

char	**parse_map(char *path)
{
	char	**map;
	char	*map_str;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error(NULL, "Wrong file path");
	map_str = read_map(fd);
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}
