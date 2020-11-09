/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:49:25 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/08 11:55:05 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	verify_player(void)
{
	int i;
	int j;
	int num_p;

	i = -1;
	j = -1;
	num_p = 0;
	while (++i < g_game.map.h)
	{
		while (++j < g_game.map.w)
		{
			if (is_map(g_game.map.map[i][j])
					|| g_game.map.map[i][j] == ' ')
			{
				if (is_p(g_game.map.map[i][j]))
					num_p++;
			}
			else
				write_exit("Error\nBad character in map");
		}
		j = 0;
	}
	check_player(num_p);
}

void	check_player(int num_p)
{
	if (num_p == 0)
		write_exit("Error\nNo player detected in map");
	else if (num_p > 1)
		write_exit("Error\nMore than one player detected in map");
}

void	get_player(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_game.map.h)
	{
		while (j < g_game.map.w)
		{
			if (is_map(g_game.map.map[i][j])
					|| g_game.map.map[i][j] == ' ')
			{
				if (is_p(g_game.map.map[i][j]))
				{
					g_player.pos.x = j * TILE_SIZE + TILE_SIZE / 2;
					g_player.pos.y = i * TILE_SIZE + TILE_SIZE / 2;
					init_angle(i, j);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	init_angle(int i, int j)
{
	if (g_game.map.map[i][j] == 'S')
		g_player.rot_angle = M_PI / 2;
	if (g_game.map.map[i][j] == 'N')
		g_player.rot_angle = 3 * M_PI / 2;
	if (g_game.map.map[i][j] == 'W')
		g_player.rot_angle = M_PI;
	if (g_game.map.map[i][j] == 'E')
		g_player.rot_angle = 0;
}
