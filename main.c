/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:48:37 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/17 17:57:37 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*char	*buffering(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];
	char	*tab;
	int		i;

	i = 0;
	tab = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (0);
		ret = read(fd, buf, BUFF_SIZE);
		close(fd);
//		buf = '\0';
		tab = malloc(sizeof(char) * ft_strlen(buf));
		tab[ft_strlen(buf)] = '\n';
		tab[ft_strlen(buf) + 1] = '\0';
		while (i < (int)ft_strlen(buf))
		{
			tab[i] = buf[i];
			i++;
		}
	}
	else
		return (0);
	return (tab);
}

int		check(char *tab)
{
	int		i;

	i = 0;
	while (i < (((int)ft_strlen(tab)) / 21))
	{
		print(ft_list_insert_back(ft_create_elem(ft_fill_btab(ft_create_btab(), tab))));
		i++;
	}
	if (check_block_hori(tab) == 1 && check_block_vert(tab) == 1
			&& check_tetriminos_nb(tab) == 1 && ft_strlen(tab) <= 546)
		return (1);
	return (0);
}

int		main2(int argc, char **argv)
{
	char	*tab;
	tab = buffering(argc, argv);
	if (check(tab) == 1)
		printf("\033[33;01m\n-----%s-----\033", "BLOCK OK"); 
	else
		printf("\033[33;01m\n-----%s-----\n\033", "BLOCK ERROR");
}*/
