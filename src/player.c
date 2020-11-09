/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:24:43 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 14:04:09 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>
void	move_player(void)
{
	float step;
	t_pos new;

	step = g_player.walk_dir * SPEED;
	g_player.rot_angle += g_player.turn_dir * ROT_SPEED;
	new.x = (g_player.pos.x + step * cos(g_player.rot_angle));
	new.y = (g_player.pos.y + step * sin(g_player.rot_angle));
	if (g_player.x_walk == 1 || g_player.x_walk == -1)
	{
		new.x = (g_player.pos.x + step * cos(g_player.rot_angle + M_PI_2));
		new.y = (g_player.pos.y + step * sin(g_player.rot_angle + M_PI_2));
	}
	if (!is_wall_at(new) && !is_sp_at(new))
	{
		g_player.pos.x = new.x;
		g_player.pos.y = new.y;
	}
}

// void move_y(void)
// {
// 	float step;
// 	t_pos new;

// 	step = g_player.walk_dir * SPEED;
// 	g_player.rot_angle += g_player.turn_dir * ROT_SPEED;
// 	new.x = (g_player.pos.x + step * cos(g_player.rot_angle));
// 	new.y = (g_player.pos.y + step * sin(g_player.rot_angle));
// 	if (g_player.walk_dir == 1)
// 	{
// 		if (!is_wall(new.x, new.y - 1) && !is_sp_at(new))
// 		{
// 			g_player.pos.x = new.x;
// 			g_player.pos.y = new.y;
// 		}
// 	}
// 	else
// 	{
// 		if(!is_wall_at(new) && !is_sp_at(new))
// 		{
// 			g_player.pos.x = new.x;
// 			g_player.pos.y = new.y;
// 		}
// 	}
// }

// void move_x(void)
// {
// 	float step;
// 	t_pos new;

// 	step = g_player.x_walk * SPEED;
// 	g_player.rot_angle += g_player.turn_dir * ROT_SPEED;
// 	new.x = (g_player.pos.x + step * cos(g_player.rot_angle + M_PI_2));
// 	new.y = (g_player.pos.y + step * sin(g_player.rot_angle + M_PI_2));
// 	if (g_player.x_walk == -1)
// 	{
// 		if (!is_wall(new.x - 1, new.y) && !is_sp_at(new))
// 		{
// 			g_player.pos.x = new.x;
// 			g_player.pos.y = new.y;
// 		}
// 	}
// 	else
// 	{
// 		if(!is_wall_at(new) && !is_sp_at(new))
// 		{
// 			g_player.pos.x = new.x;
// 			g_player.pos.y = new.y;
// 		}
// 	}
// }
