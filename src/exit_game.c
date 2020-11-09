/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:37:11 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 09:45:38 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	write_exit(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

void	load_error(char *str)
{
	if (g_tkn.no)
		free(g_tex[N_NO].path);
	if (g_tkn.so)
		free(g_tex[N_SO].path);
	if (g_tkn.we)
		free(g_tex[N_WE].path);
	if (g_tkn.ea)
		free(g_tex[N_EA].path);
	if (g_tkn.s)
		free(g_game.s_path);
	if (g_tkn.map)
		free_map();
	write_exit(str);
}

void	free_text(void)
{
	int i;

	i = -1;
	while (++i < 4)
		free(g_tex[i].path);
	free(g_game.s_path);
}

void	free_map(void)
{
	int i;

	i = 0;
	while (i < g_game.map.h)
	{
		free(g_game.map.map[i]);
		i++;
	}
	free(g_game.map.map);
}

void	exit_error(int id, char *s)
{
	if (id == 1)
	{
		free_map();
		free_text();
	}
	if (id == 2)
	{
		free_map();
		free_text();
		free(g_ray);
	}
	if (id == 3)
	{
		free_text();
		free_map();
		free(g_ray);
		free(g_sp);
	}
	mlx_clear_window(g_game.m_ptr, g_game.w_ptr);
	mlx_destroy_window(g_game.m_ptr, g_game.w_ptr);
	write(1, "Error\n", 7);
	write_exit(s);
}
