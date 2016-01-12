/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 16:17:12 by tandrieu          #+#    #+#             */
/*   Updated: 2015/12/21 16:17:14 by tandrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;

	s3 = malloc(sizeof(s3) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!s3)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcat(s3, s2);
	s3[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	return (s3);
}
