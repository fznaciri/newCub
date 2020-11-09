/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3dwall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:41:27 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/07 13:25:50 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_wall(int i)
{
	g_wall.dist = g_ray[i].dist * cos(g_ray[i].angle - g_player.rot_angle);
	g_wall.h = (TILE_SIZE / g_wall.dist) *
		((g_game.win_w / 2) / (tan(FOV / 2)));
	g_wall.top = ((g_game.win_h / 2) - (g_wall.h / 2));
	g_wall.top = g_wall.top < 0 ? 0 : g_wall.top;
	g_wall.bot = ((g_game.win_h / 2) + (g_wall.h / 2));
	g_wall.bot = g_wall.bot > g_game.win_h ? g_game.win_h : g_wall.bot;
}

void	ceeling(int i)
{
	while (g_wall.j < g_wall.top)
	{
		g_wall.color = g_game.ceeling;
		my_mlx_pixel_put(i, g_wall.j, g_wall.color);
		g_wall.j++;
	}
}

void	wall(int i)
{
	int dist_from_top;

	while (g_wall.j < g_wall.bot)
	{
		dist_from_top = g_wall.j + (g_wall.h / 2) - (g_game.win_h / 2);
		g_tex[g_wall.t].pos.y = dist_from_top *
						((float)g_tex[g_wall.t].h / g_wall.h);
		g_tex[g_wall.t].pos.y = g_tex[g_wall.t].pos.y >= g_game.win_h ?
				g_game.win_h - 1 : g_tex[g_wall.t].pos.y;
		g_wall.color = get_text_color(g_tex[g_wall.t],
						g_tex[g_wall.t].pos.x, g_tex[g_wall.t].pos.y);
		my_mlx_pixel_put(i, g_wall.j, g_wall.color);
		g_wall.j++;
	}
}

void	ground(int i)
{
	while (g_wall.j < g_game.win_h)
	{
		g_wall.color = g_game.floor;
		my_mlx_pixel_put(i, g_wall.j, g_wall.color);
		g_wall.j++;
	}
}

void	render_3dwall(void)
{
	int i;

	i = 0;
	while (i < g_game.win_w)
	{
		init_wall(i);
		g_wall.j = 0;
		g_wall.t = texture(i);
		if (g_ray[i].vert_hit)
			g_tex[g_wall.t].pos.x = (int)g_ray[i].wall_hit.y % TILE_SIZE;
		else
			g_tex[g_wall.t].pos.x = (int)g_ray[i].wall_hit.x % TILE_SIZE;
		g_tex[g_wall.t].pos.x = g_tex[g_wall.t].pos.x < 0 ?
					0 : g_tex[g_wall.t].pos.x;
		ceeling(i);
		g_wall.j = g_wall.top;
		wall(i);
		g_wall.j = g_wall.bot;
		ground(i);
		i++;
	}
}
