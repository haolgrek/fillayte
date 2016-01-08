/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:06:26 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/08 17:15:42 by rluder           ###   ########.fr       */
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

/*int		check_tetriminos_valid2(t_list *list, char *buf, int *value)
{
	printf("%s", buf);
	while (buf[value[2]] != '\0')
	{
		value[0] = 0;
		value[4] = 0;
		while (value[4] < 4)
		{
			value[1] = 0;
			while (value[1] < 5)
			{
				if (list->array[value[0]][value[1]] == buf[value[2]])
					value[3]++;
				value[1]++;
				value[2]++;
			}
			value[4]++;
			value[0]++;
		}
		printf("compteur = %d\n", value[3]);
		if (value[3] == 19)
		{
			return (1);
		}
		value[3] = 0;
	}
	return (0);
}*/

int		check_tetriminos_valid2(t_list *list, char *buf, int *value)
{
	while (buf[value[2]] != '\0')
	{
		while (value[0] < 4)
		{
			value[1] = 0;
			while (list->array[value[0]][value[1]] == buf[value[2]] && value[1] < 4)
			{
				value[3]++;
				value[2]++;
				value[1]++;
			}
			value[0]++;
		//	printf("value 0 %d\n", value[0]);
		//	printf("value 1 %d\n", value[1]);
			if (value[0] == 4 && value[1] == 4)
			{
				printf("Tetriminos ok");
				return (1);
			}
		}
		value[0] = 0;
		value[2] = value[2] + 16 - value[3] + 1;
		value[3] = 0;
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
			printf("%d\n", i);
			i++;
		}
		else
			return (0);
	}
	return (1);
}
