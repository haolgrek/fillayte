/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:34:56 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/07 11:45:42 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	**fill_tab_w_point(char **ftab, int sqrt)
{
	int		i;
	int		j;

	i = 0;
	while (i < sqrt)
	{
		j = 0;
		while (j < sqrt)
		{
			ftab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (ftab);
}

char	**create_final_tab(char *tab, int sqrt)
{
	char	**ftab;
	int		i;

	i = 0 ;
	ftab = malloc(sizeof(char*) * (sqrt));
	while (i < sqrt)
		ftab[i++] = malloc(sizeof(char) * (sqrt));
	ftab = fill_tab_w_point(ftab, sqrt);
	return (ftab);
}

void	print_tab(char **tab, int sqrt)
{
	int		i;

	i = 0;
	while (i < (sqrt - 1))
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**solve(t_list *list, char *file)
{
	char	**tab;
	int		sqrt1;

	tab = NULL;
	sqrt1 = sqrt(((strlen(file) + 1) / 21) * 4);
	if (sqrt1 != 2 && sqrt1 != 4 && sqrt1 != 9 && sqrt1 != 16 && sqrt1 != 25 && sqrt1 != 36 && sqrt1 != 49 && sqrt1 != 64 && sqrt1 != 81 && sqrt1 != 100)
		sqrt1 += 1;
	while (tab == NULL)
	{
		tab = create_final_tab(file, sqrt1);
		tab = backtracking(tab, list, sqrt1);
		sqrt1++;
	}
	print_tab(tab, sqrt1);
	return (0);
}
