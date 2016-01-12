/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:06:26 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/12 14:06:15 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

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

int		check_tetriminos_valid2(t_list *list, char *buf)
{
	int		var[3];
	char	tetri[17];

	var[0] = 0;
	var[1] = 0;
	while (var[1] < 4)
	{
		var[2] = 0;
		while (var[2] < 4)
		{
			tetri[var[0]] = list->array[var[1]][var[2]];
			var[2]++;
			var[0]++;
		}
		var[1]++;
	}
	tetri[var[0]] = '\0';
	if (check_tetriminos_valid3(buf, tetri) == 1)
		return (1);
	return (0);
}

int		check_tetriminos_valid(t_list *list)
{
	char	*tab[5];
	char	*buf;
	int		i;

	i = 0;
	tab[0] = "####............#...#...#...#...###..#..........#...##..#......";
	tab[1] = "..#..##...#.......#..###.........##..##..........###...#.......";
	tab[2] = "..##..#...#.......#...###..........#...#..##........#.###......";
	tab[3] = "...##...#...#......###.#...........#...#...##.......##.##......";
	tab[4] = "....##...##.........#...##...#.......#..##..#.......";
	buf = ft_strjoin(tab[0], tab[1]);
	buf = ft_strjoin(buf, tab[2]);
	buf = ft_strjoin(buf, tab[3]);
	buf = ft_strjoin(buf, tab[4]);
	while (list)
	{
		if (check_tetriminos_valid2(list, buf) == 1)
		{
			list = list->next;
			i++;
		}
		else
			return (0);
	}
	return (1);
}
