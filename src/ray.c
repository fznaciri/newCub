/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:44:01 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/07 11:53:49 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_horz(int id)
{
	g_horz.hit = 0;
	g_horz.wall.x = 0;
	g_horz.wall.y = 0;
	g_horz.step.y = TILE_SIZE;
	g_horz.step.y *= (g_ray[id].ray_d ? 1 : -1);
	g_horz.step.x = g_horz.step.y / tan(g_ray[id].angle);
	g_horz.inter.y = floor(g_player.pos.y / TILE_SIZE) * TILE_SIZE;
	g_horz.inter.y += (g_ray[id].ray_d ? TILE_SIZE : 0);
	g_horz.inter.x = g_player.pos.x +
					((g_horz.inter.y - g_player.pos.y) / tan(g_ray[id].angle));
	g_horz.next.x = g_horz.inter.x;
	g_horz.next.y = g_horz.inter.y;
}

void	cast_horz(int id)
{
	int check;

	init_horz(id);
	check = g_ray[id].ray_up ? -1 : 0;
	while ((g_horz.next.x >= 0 && g_horz.next.x < g_game.map.w * TILE_SIZE)
			&& (g_horz.next.y >= 0 && g_horz.next.y < g_game.map.h * TILE_SIZE))
	{
		if (is_wall(g_horz.next.x, g_horz.next.y + check))
		{
			g_horz.hit = 1;
			g_horz.wall.x = g_horz.next.x;
			g_horz.wall.y = g_horz.next.y;
			break ;
		}
		else
		{
			g_horz.next.x += g_horz.step.x;
			g_horz.next.y += g_horz.step.y;
		}
	}
}

void	init_vert(int id)
{
	g_vert.hit = 0;
	g_vert.wall.x = 0;
	g_vert.wall.y = 0;
	g_vert.step.x = TILE_SIZE;
	g_vert.step.x *= (g_ray[id].ray_l ? -1 : 1);
	g_vert.step.y = g_vert.step.x * tan(g_ray[id].angle);
	g_vert.inter.x = floor(g_player.pos.x / TILE_SIZE) * TILE_SIZE;
	g_vert.inter.x += (g_ray[id].ray_r ? TILE_SIZE : 0);
	g_vert.inter.y = g_player.pos.y +
					((g_vert.inter.x - g_player.pos.x) * tan(g_ray[id].angle));
	g_vert.next.x = g_vert.inter.x;
	g_vert.next.y = g_vert.inter.y;
}

void	cast_vert(int id)
{
	int check;

	init_vert(id);
	check = g_ray[id].ray_l ? -1 : 0;
	while ((g_vert.next.x >= 0 && g_vert.next.x < g_game.map.w * TILE_SIZE)
			&& (g_vert.next.y > 0 && g_vert.next.y <= g_game.map.h * TILE_SIZE))
	{
		if (is_wall(g_vert.next.x + check, g_vert.next.y))
		{
			g_vert.hit = 1;
			g_vert.wall.x = g_vert.next.x;
			g_vert.wall.y = g_vert.next.y;
			break ;
		}
		else
		{
			g_vert.next.x += g_vert.step.x;
			g_vert.next.y += g_vert.step.y;
		}
	}
}
