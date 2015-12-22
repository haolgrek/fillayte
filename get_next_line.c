/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:57:08 by rluder            #+#    #+#             */
/*   Updated: 2015/12/17 18:00:52 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*ft_nofile(int const fd, char *file, char *buf)
{
	int	ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!file)
			file = ft_strdup(buf);
		else
			file = ft_strjoin(file, buf);
	}
	return (file);
}

int	get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static char		*file;
	unsigned int	index;
	unsigned int	len;

	index = 0;
	len = 0;
//	if (BUFF_SIZE <= 0 || !line)
//		return (write(1, "nope\n", 5));
//		return (-1);
	if (!file)
		file = ft_nofile(fd, file, buf);
	if (*file == '\0')
	{
		return (write(1, "-1\n", 3));
		return (-1);
	}
	while (file[index] != '\n' && file[index] != '\0')
	{
		len++;
		index++;
	}
	line = malloc(sizeof(char) * (len + 1));
	(*line) = ft_strsub(file, 0, len);
	file = &file[len];
	file++;
//	ft_putstr((*line));
//	write(1, "\n\n", 2);
//	ft_putstr(file);
	if (file[len + 1] == '\0')
	{
		return (write(1, "0\n", 2));
		return (0);
	}
	return (write(1, "1\n", 2));
	return (1);
}

int main(int argc, const char *argv[])
{
	char	**line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);
	get_next_line(fd, line);
	get_next_line(fd, line);
//	get_next_line(fd, line);
//	get_next_line(fd, line);
//	get_next_line(fd, line);
//	get_next_line(fd, line);
	return (0);
}*/
