/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:30:59 by rluder            #+#    #+#             */
/*   Updated: 2016/01/06 18:38:02 by rluder           ###   ########.fr       */
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
	t_list	*list;
	char	*file;
	int		fd;
	int		i;
	t_list *begin;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	file = get_BUFF(fd);
	list = create_list(file);
	print(list);
	begin = list;
	if (check_block_hori(file) == 1 && check_block_vert(file) == 1
			&& check_tetriminos_nb(file) == 1 && ft_strlen(file) <= 546)
	{
	//	write(1, "HALLO\n", 6);
		if (check_tetriminos_valid(list) == 0)
		{
		//	write(1, "HMLLO\n", 6);
			return (0);
		}
		else
		{
//			write(1, "HPLLO\n", 6);
		//	print(list);
			list = list->next;
	//		write(1, "HPLLO\n", 6);
		}
		i++;
	}
	else
		return (0);
//	write(1, "HILLO\n", 6);
	//print(begin);
	solve(begin, file);
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
			printf("%s\n", "block ok");
		}
		else
			printf("%s\n", "block error");
	}
}
