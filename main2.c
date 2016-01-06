/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:30:59 by rluder            #+#    #+#             */
/*   Updated: 2016/01/05 15:52:59 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

static char			*ft_nofile(int const fd, char *file, char *buf)
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

char				*get_BUFF(int const fd)
{
	char			buf[BUFF_SIZE + 1];
	static char		*file;

	if (!file)
		file = ft_nofile(fd, file, buf);
	if (*file == '\0')
		return (0);
	return (file);
}

int					han_shot_first(char **argv)
{
	int		index;
	char	**tab;
	t_list	*list;
	char	*file;
	int		fd;
	int		i;

	i = 0;
	index = 0;
	fd = open(argv[1], O_RDONLY);
	file = get_BUFF(fd);
	if (check_block_hori(file) == 1 && check_block_vert(file) == 1
			&& check_tetriminos_nb(file) == 1 && ft_strlen(file) <= 546)
	{
		while (i <= (ft_strlen(file) / 21))
		{
			list = everything_is_done_in_here_WTF(file);
			index = index + 21;
			if (check_tetriminos_valid(list) == 0)
				return (0);
			i++;
		}
	}
	else
		return (0);
	fd = check_tetriminos_valid(list);
	printf("valid? %d\n", fd);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
	{
		if (han_shot_first(argv) == 1)
		{
		}
		else
			printf("%s\n", "block error");
	}
}
