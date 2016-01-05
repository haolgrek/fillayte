/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rluder <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:05:13 by rluder            #+#    #+#             */
/*   Updated: 2016/01/04 11:53:12 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft.h"
#include <fcntl.h>

char	*create_compare(t_list list, char *file)
{
	int		fd;

	fd = open("tetriminos_valid.tetriminos", O_RDONLY);
	file = get_BUFF(fd);
	return (file);
}

int	compare(t_list *list)
{
	char	*file;
	int		index;

	index = 0;
	file = create_compare(*list, file);
	while (list->next) //PREND PAS EN COMPTE LE DERNIER?
	{
		if (ft_strncmp((char*)list->array, file, 20) != 0)
		{
			list->type = index;
			index = 0;
			list = list->next;
		}
		else if (ft_strncmp((char*)list->array, file, 20) == 0)
		{
			index++;
			file = file + 20;
		}
	}
}
