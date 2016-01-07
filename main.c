/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:30:59 by rluder            #+#    #+#             */
/*   Updated: 2016/01/07 12:12:46 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static char			*ft_nofile(int const fd, char *file, char *buf)
{
	int	ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		write(1, "while", 5);
		buf[ret] = '\0';
		if (!file)
		{
			write(1, "bate", 4);
			file = ft_strdup(buf);
		}
		else
			write(1, "bete", 4);
			file = ft_strjoin(file, buf);
	}
	return (file);
}

char				*get_BUFF(int const fd)
{
	char			buf[BUFF_SIZE + 1];
	static char		*file;

	if (!file)
		write(1, "bite", 4);
		file = ft_nofile(fd, file, buf);
	if (*file == '\0')
		write(1, "bote", 4);
		return (0);
	return (file);
}

int					han_shot_first(char **argv)
{
	t_list	*list;
	t_list	*tempo;
	char	*file;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	write(1, "bute", 4);
	file = get_BUFF(fd);
	close(fd);
	write(1, "bite", 4);
	list = create_list(file);
	list = ft_move(list);
	if (check_block_hori(file) == 1 && check_block_vert(file) == 1
			&& check_tetriminos_nb(file) == 1 && ft_strlen(file) <= 546)
	{
		if (check_tetriminos_valid(list) == 0)
			return (0);
	}
	else
		return (0);
	solve(list, file);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
	{
		if (han_shot_first(argv) == 0)
			printf("%s\n", "error");
	}
}
