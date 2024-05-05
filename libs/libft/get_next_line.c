/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:41:46 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/04 14:14:21 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_file(int fd, char *store, char *buffer)
{
	char		*tmp;
	ssize_t		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!store)
			store = ft_strdup("");
		tmp = store;
		store = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (store);
}

static char	*process_store(char *line)
{
	int		i;
	char	*rest;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line + i + 1));
	if (!rest)
		return (NULL);
	line[i + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*store = NULL;
	char		*line;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_file(fd, store, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	store = process_store(line);
	return (line);
}
