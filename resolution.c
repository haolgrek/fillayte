/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:34:56 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/05 15:22:25 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

char	**fill_tab_w_point(char **ftab, int sqrt_calc)
{
	int		i;
	int		j;

	i = 0;
	printf("%d\n", sqrt_calc);
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			ftab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (ftab);
}

char	**create_final_tab(char *tab)
{
	char	**ftab;
	int		i;
	int		sqrt_calc;
	static int k;

	i = strlen(tab) / 21;
	sqrt_calc = sqrt(strlen(tab) / 21); //FT_STRLEN !!!
	if (i != 4 && i != 9 && i != 16 && i != 25 && i != 36 && i != 49 &&
			i != 64 && i != 81 && i  != 100)
		sqrt_calc += 1;
	ftab = malloc(sizeof(char*) * sqrt_calc + k);
	i = 0 ;
	while (i < sqrt_calc + k)
		ftab[i++] = malloc(sizeof(char) * sqrt_calc + k);
	k++;
	return (ftab);
}
