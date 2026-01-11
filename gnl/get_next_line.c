
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 04:23:38 by bfathi            #+#    #+#             */
/*   Updated: 2025/11/10 22:26:53 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*free_and_null(char *buffer, char *tmp)
{
	if (buffer)
		free(buffer);
	if (tmp)
		free(tmp);
	return (NULL);
}

int	main_loop(int bytes, int fd, char *tmp, char **buffer)
{
	char	*to_free;

	while (!gnl_strchr(*buffer, '\n'))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
			return (*buffer = free_and_null(*buffer, tmp), 1);
		if (bytes == 0)
			break ;
		tmp[bytes] = '\0';
		to_free = *buffer;
		*buffer = gnl_strjoin(*buffer, tmp);
		free(to_free);
		if (!*buffer)
			return (free(tmp), 1);
	}
	return (0);
}

void	cat_buff(char *buffer, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	tmp = gnl_substr(buffer, 0, i);
	if (!tmp)
		return ;
	free(*line);
	*line = tmp;
}

void	remove_line(char **buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	tmp = gnl_substr(*buffer, i, gnl_strlen(*buffer) - i);
	free(*buffer);
	*buffer = tmp;
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	char		*line;
	int			bytes;

	if ((size_t)BUFFER_SIZE <= 0 || (size_t)BUFFER_SIZE >= SIZE_MAX)
		return (0);
	bytes = 0;
	tmp = malloc((size_t)BUFFER_SIZE + 1);
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !tmp)
		return (free_and_null(NULL, tmp));
	if (!buffer)
		buffer = gnl_strdup("");
	if (main_loop(bytes, fd, tmp, &buffer))
		return (NULL);
	if (!buffer || *buffer == '\0')
		return (buffer = free_and_null(buffer, tmp), NULL);
	cat_buff(buffer, &line);
	remove_line(&buffer);
	return (free(tmp), line);
}
