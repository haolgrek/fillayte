/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:06:26 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/08 19:37:34 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		check_block_hori(char *tab)
{
	int		i;
	int		block4;
	int		enter;

	i = 0;
	enter = 0;
	block4 = 0;
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

int		check_tetriminos_valid2(t_list *list, char *buf, int *value)
{
	int		k;
	char	tetri[17];

	k = 0;
	value[0] = 0;
	tetri[0] = list->array[0][0];
	tetri[1] = list->array[0][1];
	tetri[2] = list->array[0][2];
	tetri[3] = list->array[0][3];
	tetri[4] = list->array[1][0];
	tetri[5] = list->array[1][1];
	tetri[6] = list->array[1][2];
	tetri[7] = list->array[1][3];
	tetri[8] = list->array[2][0];
	tetri[9] = list->array[2][1];
	tetri[10] = list->array[2][2];
	tetri[11] = list->array[2][3];
	tetri[12] = list->array[3][0];
	tetri[13] = list->array[3][1];
	tetri[14] = list->array[3][2];
	tetri[15] = list->array[3][3];
	tetri[16] = '\0';
	while (k != 19)
	{
		if (!ft_strncmp(buf, tetri, 16))
			return (1);
		else
			buf = buf + 16;
		k++;
	}
	return (0);
}

int		check_tetriminos_valid(t_list *list)
{
	int		fd;
	int		ret;
	char	buf[400];
	int		value[5];

	value[2] = 0;
	value[3] = 0;
	value[4] = 0;
	fd = open("tetriminos_valid.tetriminos", O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, buf, 400);
	buf[ret + 1] = '\0';
	close(fd);
	int i;
	i = 0;
	while (list)
	{
		if (check_tetriminos_valid2(list, buf, value) == 1)
		{
			list = list->next;
			i++;
		}
		else
			return (0);
	}
	return (1);
}
