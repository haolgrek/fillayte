/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:39:49 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/04 17:23:35 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(char **btab)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->array = btab;
		list->next = NULL;
	}
	free(btab);
	write(1, "elemOK\n", 7);
	return (list);
}

t_list	*ft_list_insert_back(t_list *list)
{
	t_list	*begin_list;

	begin_list = list;
	if (list)
	{
		while (list->next)
			list = list->next;
	}
	write(1, "backOK\n", 7);
	return (begin_list);
}

char	**ft_create_btab(char *file)
{
	char	**btab;
	int		x;

	btab = malloc(sizeof(char*) * 4);
	if (!btab)
	{
		return (0);
	}
	x = 0;
	while (x < 4)
	{
		btab[x++] = malloc(sizeof(char) * 5);
	}
	btab = ft_fill_btab(btab, file);
	return (btab);
}

char	**ft_fill_btab(char **btab, char *file)
{
	int			x;
	int			y;
	int			j;
	static int	i;

	if (i == 0)
		i = -1;
	if (i != 0)
		i++;
	j = 0;
	x = 0;
	y = 0;
	while (j < 4)
	{
		while (y < 4)
		{
			while (x < 5)
			{
				btab[y][x] = file[i];
				x++;
				i++;
			}
			j++;
			y++;
			x = 0;
		}
		y = 0;
		x = 0;
	}
	btab[3][4] = '\0';
	write(1, "fillOK\n", 7);
	return (btab);
}

void	print(t_list *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	list = ft_move(list);
	while (list)
	{
		while (i < 4)
		{
			printf("%s", list->array[i]);
			i++;
		}
		printf("%c", '\n');
		printf("%c", '\n');
		list = list->next;
	}
}

t_list	*everything_is_done_in_here_WTF(char *file)
{
	t_list	*list;
	
	write(1, "inWTF\n", 6);
	list = ft_move(ft_list_insert_back(ft_create_elem(ft_create_btab(file))));
	write(1, "doneWTF\n", 8);
	print(list);
	write(1, "printok\n", 8);
	return (list);
}
