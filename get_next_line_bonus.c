/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabayan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:35:26 by tbabayan          #+#    #+#             */
/*   Updated: 2022/03/28 15:40:39 by tbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

char	*ft_strjoinfree(char *saved, char *buffer)
{
	char	*p;

	if (!buffer)
		return (NULL);
	p = ft_strjoin(saved, buffer);
	if (saved)
		free(saved);
	return (p);
}

int	ft_strlen_n(char *saved)
{
	int	i;

	i = 0;
	if (!saved)
		return (0);
	while (saved[i] != '\n')
		i++;
	return (i);
}

char	*ft_edit(char **saved, int fd)
{
	char	*line;
	char	*todelete;

	if (!(saved[fd]))
		return (NULL);
	line = NULL;
	if (ft_strchr(saved[fd], '\n'))
	{
		line = ft_substr(saved[fd], 0, ft_strlen_n(saved[fd]) + 1);
		todelete = ft_strdup(saved[fd] + ft_strlen_n(saved[fd]) + 1);
		if (*todelete == '\0')
		{
			free(todelete);
			todelete = NULL;
		}
		free(saved[fd]);
		saved[fd] = todelete;
	}
	return (line);
}

char	*ft_read(int fd, char **saved, char *line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		readen;

	readen = 1;
	while (readen != 0)
	{
		readen = read(fd, buffer, BUFFER_SIZE);
		if (readen == -1)
			return (NULL);
		buffer[readen] = '\0';
		if (readen > 0)
			saved[fd] = ft_strjoinfree(saved[fd], buffer);
		line = ft_edit(saved, fd);
		if (line)
			return (line);
	}
	line = ft_strdup(saved[fd]);
	free(saved[fd]);
	saved[fd] = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved[65537];

	if (fd < 0 || fd > 65536 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_edit(&saved[fd], fd);
	if (line)
		return (line);
	line = ft_read(fd, &saved[fd], line);
	return (line);
}
