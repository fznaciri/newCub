/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:37:13 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/12 14:54:09 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize_window(void)
{
	g_game.m_ptr = mlx_init();
	if (!g_game.m_ptr)
		write_exit("ERROR\nINITIALIZING THE SERVER.\n");
	g_game.w_ptr = mlx_new_window(g_game.m_ptr,
					g_game.win_w, g_game.win_h, "Cub3D");
	if (!g_game.w_ptr)
		write_exit("ERROR\nCREATING THE WINDOW.\n");
	g_img.img = mlx_new_image(g_game.m_ptr, g_game.win_w, g_game.win_h);
	g_img.addr = mlx_get_data_addr(g_img.img,
					&g_img.bpp, &g_img.length, &g_img.e);
}

void	init_sprite(int k, int *ws, int *hs)
{
	int a;

	g_sp[k].ptr = mlx_xpm_file_to_image(g_game.m_ptr, g_game.s_path, ws, hs);
	if (g_sp[k].ptr == NULL)
		exit_error(3, "Error loading sprite\n");
	g_sp[k].data = (int *)mlx_get_data_addr(g_sp[k].ptr, &a, &a, &a);
}

void	load_texture(t_tex *tex)
{
	tex->tex.img = mlx_xpm_file_to_image(g_game.m_ptr,
					tex->path, &tex->w, &tex->h);
	if (!tex->tex.img)
		exit_error(3, "failed to load the texture");
	tex->tex.addr = mlx_get_data_addr(tex->tex.img,
			&tex->tex.bpp, &tex->tex.length, &tex->tex.e);
}

void	setup(void)
{
	g_player.turn_dir = 0;
	g_player.walk_dir = 0;
	sp_count();
	if (!(g_ray = malloc(sizeof(t_ray) * g_game.win_w)))
		exit_error(1, "Rays allocation fails");
	if (!(g_sp = malloc(sizeof(t_sp) * g_game.sp_num)))
		exit_error(2, "Sprite allocation fails");
	initialize_window();
	process_input();
	set_text();
	sp_pos();
}
