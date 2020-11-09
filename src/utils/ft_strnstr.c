/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:12:27 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 09:33:10 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	str = (char*)s1;
	to_find = (char*)s2;
	if (to_find[0] == '\0')
		return ((char*)s1);
	i = 0;
	j = 0;
	while (str[i + j] != '\0' && i < n)
	{
		while (str[i + j] == to_find[j] && i + j < n)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char*)s1 + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
