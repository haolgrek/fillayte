/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:06:26 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/17 18:27:19 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int		check_block_hori(char *tab)
{
	int		i;
	int		block4;
	int		enter;

	i = 0;
	enter = 0;
	block4 = 0;
	write(1, "hori\n", 5);
	while (tab[i] != '\0')
	{
		if (enter == 4)
			enter = 0;
		else if (tab[i] == '.' || tab[i] == '#')
			block4++;
		else if (tab[i] == '\n' && block4 == 4)
		{
			block4 = 0;
			enter++;
		}
		else
			return (0);
		i++;
	}
	return (1);
}

int		check_block_vert(char *tab)
{
	int		i;
	int		block4;

	i = 0;
	block4 = 0;
	while (tab[i] != '\0')
	{
		if ((tab[i] == '.' || tab[i] == '#') && block4 != 4)
		{
			block4++;
			i += 5;
		}
		else if (tab[i] == '\n' && block4 == 4)
		{
			block4 = 0;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int		check_tetriminos_nb(char *tab)
{
	int		i;
	int		point;
	int		enter;

	i = 0;
	point = 0;
	enter = 0;
	while (tab[i] != '\0')
	{
		if (enter == 4 && point != 12)
			return (0);
		else if (enter == 4)
		{
			enter = 0;
			point = 0;
		}
		else if (tab[i] == '.')
			point++;
		else if (tab[i] == '\n')
			enter++;
		i++;
	}
	return (1);
}

int		check_tetriminos_valid2(t_list *list, char *buf)
{
	int		i;
	int		j;
	int		k;
	int		enter;
	int		count;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	enter = 0;
	while (buf[k] != '\0')
	{
		while (enter < 4)
		{
			while (j < 5)
			{
				if (list->array[i][j] == buf[k])
					count++;
				j++;
				k++;
			}
			enter++;
			i++;
			j = 0;
		}
		if (count == 19)
			return (1);
		count = 0;
		enter = 0;
		i = 0;
		j = 0;
	}
	return (0);
}

int		check_tetriminos_valid(t_list *list)
{
	int		fd;
	int		ret;
	char	buf[400];

	fd = open("tetriminos_valid.tetriminos", O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, buf, 400);
	close(fd);
	while (list)
	{
		if (check_tetriminos_valid2(list, buf) == 1)
			list = list->next;
		else
			return (0);
	}
	return (1);
}
