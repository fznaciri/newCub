/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:20:10 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 10:46:00 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		key_down(int key)
{
	if (key == 53)
		destroy_window();
	if (key == 123)
		g_player.turn_dir = -1;
	if (key == 0)
	{
		g_player.walk_dir = -1;
		g_player.x_walk = -1;
	}
	if (key == 124)
		g_player.turn_dir = 1;
	if (key == 2)
	{
		g_player.walk_dir = 1;
		g_player.x_walk = 1;
	}
	if (key == 13 || key == 126)
		g_player.walk_dir = 1;
	if (key == 1 || key == 125)
		g_player.walk_dir = -1;
	return (0);
}

int		key_up(int key)
{
	if (key == 123 || key == 124)
		g_player.turn_dir = 0;
	if (key == 13 || key == 1 || key == 126 || key == 125)
		g_player.walk_dir = 0;
	if (key == 0 || key == 2)
	{
		g_player.walk_dir = 0;
		g_player.x_walk = 0;
	}
	return (0);
}

int		destroy_window(void)
{
	mlx_clear_window(g_game.m_ptr, g_game.w_ptr);
	mlx_destroy_window(g_game.m_ptr, g_game.w_ptr);
	free_text();
	free_map();
	free(g_ray);
	free(g_sp);
	exit(0);
	return (0);
}

void	process_input(void)
{
	mlx_hook(g_game.w_ptr, EVENT_KEYDOWN, 0, key_down, (void*)0);
	mlx_hook(g_game.w_ptr, EVENT_KEYUP, 0, key_up, (void*)0);
	mlx_hook(g_game.w_ptr, EVENT_EXIT, 0, destroy_window, (void*)0);
}
