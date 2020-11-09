/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:42:44 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/07 13:31:17 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cast_ray(int id)
{
	g_ray[id].angle = normalize_angle(g_ray[id].angle);
	g_ray[id].ray_d = ((g_ray[id].angle > 0 && g_ray[id].angle < M_PI) ? 1 : 0);
	g_ray[id].ray_up = !g_ray[id].ray_d;
	g_ray[id].ray_r = ((g_ray[id].angle < M_PI * 0.5
						|| g_ray[id].angle > 1.5 * M_PI) ? 1 : 0);
	g_ray[id].ray_l = !g_ray[id].ray_r;
	cast_horz(id);
	cast_vert(id);
	g_horz.dist = g_horz.hit ? distance(g_player.pos.x, g_player.pos.y,
					g_horz.wall.x, g_horz.wall.y) : MAX_INT;
	g_vert.dist = g_vert.hit ? distance(g_player.pos.x,
					g_player.pos.y, g_vert.wall.x, g_vert.wall.y) : MAX_INT;
	if (g_vert.dist < g_horz.dist)
	{
		g_ray[id].dist = g_vert.dist;
		set_pos(&(g_ray[id].wall_hit), g_vert.wall.x, g_vert.wall.y);
		g_ray[id].vert_hit = 1;
	}
	else
	{
		g_ray[id].dist = g_horz.dist;
		set_pos(&(g_ray[id].wall_hit), g_horz.wall.x, g_horz.wall.y);
		g_ray[id].vert_hit = 0;
	}
}

void	cast_allrays(void)
{
	int		i;
	float	ray_angle;

	i = 0;
	ray_angle = g_player.rot_angle - (FOV / 2);
	while (i < g_game.win_w)
	{
		g_ray[i].angle = ray_angle;
		cast_ray(i);
		ray_angle += FOV / g_game.win_w;
		i++;
	}
}
