/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:11:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/07 11:08:57 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		bigger(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

void	skip_digit(char **s)
{
	while (ft_isdigit(**s))
		(*s)++;
}
