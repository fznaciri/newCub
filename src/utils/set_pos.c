/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:21:26 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/07 11:16:45 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

t_pos	set_pos(t_pos *pos, float x, float y)
{
	pos->x = x;
	pos->y = y;
	return (*pos);
}
