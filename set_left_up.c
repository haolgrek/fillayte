/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_left_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:56:46 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/22 19:04:57 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

int		ft_count_hori(t_list *list)
{
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 4;
	while (list)
	{
		while (i < 4)
		{
			while (list->array[i][j] != '#' && j < 5)
				j++;
			if (j < x)
				x = j;
			j = 0;
			i++;
		}
		return (x);
		x = 4;
		list = list->next;
	}
	return (0);
}

int		ft_count_vert(t_list *list)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	y = 0;
	while (list)
	{
		while (i < 4)
		{
			while (list->array[i][j] != '#' && j < 5)
				j++;
			if (j == 5)
				y++;
			else
				return (y);
			j = 0;
			i++;
		}
		y = 4;
		list = list->next;
	}
	return (0);
}

t_list	*ft_move(t_list *list)
{
	t_list	*begin;
	int		i;
	int		j;
	int		x;
	int		y;

	begin = list;
	i = 0;
	j = 0;
	x = ft_count_hori(list);
	y = ft_count_vert(list);
	while (list)
	{
		ft_move_vert(list, y);
		ft_move_hori(list, x);
		list = list->next;
	}
	return (begin);
}

t_list	*ft_move_hori(t_list *list, int x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (x)
	{
		while (i < 4)
		{
			while (j < 3)
			{
				list->array[i][j] = list->array[i][j + 1];
				list->array[i][j + 1] = '.';
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
	 	x--;
	}
	return (list);
}

t_list	*ft_move_vert(t_list *list, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (y)
	{
		while (i < 3)
		{
			while (j < 4)
			{
				list->array[i][j] = list->array[i + 1][j];
				list->array[i + 1][j] = '.';
				j++;
			}
			j = 0;
			i++;
		}
		i = 0;
		y--;
	}
	return (list);
}