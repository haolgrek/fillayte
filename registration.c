/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registration.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:39:49 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/06 18:43:51 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

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
	return (btab);
}

void	print(t_list *list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (list)
	{
		while (i < 4)
		{
			printf("%s", list->array[i]);
			i++;
		}
		i = 0;
		printf("%c", '\n');
		list = list->next;
	}
}

t_list	*create_list(char *file)
{
	t_list	*list;
	//t_list	*begin;
	int		b;

	b = 0;
	list = NULL;
	while (b < ((ft_strlen(file) + 1)/ 21))
	{
		list = ft_list_insert_back(list, file);
		//print(list);
	//	printf("rappelle\n");
		//if (b == 0)
		//{
			//write(1, "HiiLO\n", 6);
		//	begin = list;
//			print(begin);
//		}
		b++;
	}
	//print(begin);
	//write(1, "HELLO\n", 6);
	return (list);
}

t_list	*ft_create_elem(char *file)
{
	t_list		*lst;
	static int	k;
	char		**btab;

	btab = ft_create_btab(file);
	lst = malloc(sizeof(t_list));
	if (lst)
	{
		lst->array = btab;
		lst->index = k;
		lst->next = NULL;
	}
	k = k + 1;
	return (lst);
}

t_list	*ft_list_insert_back(t_list *list, char *file)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = ft_create_elem(file);
	if (tmp)
	{
		if (list)
		{
		//	printf("second appel\n");
			tmp2 = list;
			while (tmp2->next)
			{
			//	write(1, "BONJOUP\n", 8);
				tmp2 = tmp2->next;
			}
		//	write(1, "BONJOUm\n", 8);
			tmp2->next = tmp;
		//	write(1, "BONJOUO\n", 8);
		}
		else
		{
			list = tmp;
	//		print(list);
	//		printf("premier appel\n");
		}
	}
	//print(list);
	//print(list->next);
//	write(1, "BYNJOUR\n", 8);
	return (list);
}
