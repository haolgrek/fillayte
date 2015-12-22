/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:30:59 by rluder            #+#    #+#             */
/*   Updated: 2015/12/22 20:20:56 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "list.h"
#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/*t_list				*ft_create_list(char **tab, t_list *list)
{
	char	**btab;
	int		x;

	x = 0;
	btab = malloc(sizeof(char) * 5);
	write (1, "creat1\n", 7);
	list = 0;
	write (1, "creat2\n", 7);
	while (x < 4)
	{
		write (1, "creat3\n", 7);
		btab[x] = malloc(sizeof(char) * 5);
		x++;
	}
	write (1, "creat4\n", 7);
	btab = ft_fill_btab(btab, tab);
	write (1, "creat5\n", 7);
	list = ft_list_insert_back(ft_create_elem(btab, list));
	write (1, "creat6\n", 7);
	free (btab);
	write (1, "creat7\n", 7);
	return (list);
}*/

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

int					main(int argc, const char *argv[])
{
	int		index;
	char	**tab;
	t_list	*list;
	char	*file;
	int		fd;
//	int		i;
//	int		j;

//	i = 0;
	index = 0;
	fd = open(argv[1], O_RDONLY);
	file = get_BUFF(fd);
	if (check_block_hori(file) == 1 && check_block_vert(file) == 1
			&& check_tetriminos_nb(file) == 1 && ft_strlen(file) <= 546)
	{
		while (file[index] != '\0')
		{
			write (1, "gne\n", 4);
			write(1, &file[index], 1);
			write(1, "\n", 1);
			list = everything_is_done_in_here_WTF(file);
			index = index + 21;
		}
	}
	return (0);
}
