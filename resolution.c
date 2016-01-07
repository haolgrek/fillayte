/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:34:56 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/06 13:10:30 by rluder           ###   ########.fr       */
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
	static int k;

	i = 0 ;
	ftab = malloc(sizeof(char*) * (sqrt + k));
	while (i < sqrt + k)
		ftab[i++] = malloc(sizeof(char) * (sqrt + k));
	k++;
	ftab = fill_tab_w_point(ftab, sqrt);
	print_tab(ftab, sqrt);
	return (ftab);
}

void	print_tab(char **tab, int sqrt)
{
	int		i;

	i = 0;
	while (i < sqrt)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

char	**solve(t_list *list, char *file)
{
	char	**tab;
	int		sqrt;
	sqrt = (strlen(file) + 1)/ 21;
	if (sqrt != 4 && sqrt != 9 && sqrt != 16 && sqrt != 25 && sqrt != 36 && sqrt != 49 && sqrt != 64 && sqrt != 81 && sqrt != 100)
		sqrt += 1;
	tab = create_final_tab(file, sqrt);
	//write (1, "teub\n", 5);
	printf("__Before Backtracking__\n");
	tab = backtracking(tab, list, sqrt);
	printf("__After Backtracking__\n");
	print_tab(tab, sqrt);
	return (0);
}
