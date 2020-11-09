/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:27:42 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 10:53:50 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		is_wall(float x, float y)
{
	int index_x;
	int index_y;

	if (x < 0 || x > g_game.map.w * TILE_SIZE
			|| y < 0 || y > g_game.map.h * TILE_SIZE)
		return (TRUE);
	index_x = floor(x / TILE_SIZE);
	index_y = floor(y / TILE_SIZE);
	return (g_game.map.map[index_y][index_x] == '1' ? 1 : 0);
}

int		is_sp(float x, float y)
{
	int index_x;
	int index_y;

	if (x < 0 || x > g_game.map.w * TILE_SIZE
			|| y < 0 || y > g_game.map.h * TILE_SIZE)
		return (TRUE);
	index_x = floor(x / TILE_SIZE);
	index_y = floor(y / TILE_SIZE);
	return (g_game.map.map[index_y][index_x] == '2' ? 1 : 0);
}

int		is_wall_at(t_pos pos)
{
	int index_x;
	int index_y;

	if (pos.x < 0 || pos.x > g_game.map.w * TILE_SIZE
			|| pos.y < 0 || pos.y > g_game.map.h * TILE_SIZE)
		return (TRUE);
	index_x = floor(pos.x / TILE_SIZE);
	index_y = floor(pos.y / TILE_SIZE);
	if (g_player.walk_dir == 1 && g_player.rot_angle >= M_PI
			&& g_player.rot_angle <= 2 * M_PI)
		index_y = (floor((pos.y - 1)) / TILE_SIZE);
	if (g_player.walk_dir == 1 && g_player.rot_angle >= M_PI / 2
			&& g_player.rot_angle <= 1.5 * M_PI)
		index_x = (floor((pos.x - 1)) / TILE_SIZE);
	return (g_game.map.map[index_y][index_x] == '1' ? 1 : 0);
}

int		is_sp_at(t_pos pos)
{
	int index_x;
	int index_y;

	if (pos.x < 0 || pos.x > g_game.map.w * TILE_SIZE
			|| pos.y < 0 || pos.y > g_game.map.h * TILE_SIZE)
		return (TRUE);
	index_x = floor(pos.x / TILE_SIZE);
	index_y = floor(pos.y / TILE_SIZE);
	return (g_game.map.map[index_y][index_x] == '2' ? 1 : 0);
}
