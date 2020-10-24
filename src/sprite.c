#include "../include/cub3d.h"

void	init_sprite(int k, int *ws, int *hs)
{
	int a;

	g_sp[k].ptr = mlx_xpm_file_to_image(g_game.m_ptr, g_game.s_path, ws, hs);
	if (g_sp[k].ptr == NULL)
	{
		write_exit("Error loading sprite\n");
		
	}
	g_sp[k].data = (int *)mlx_get_data_addr(g_sp[k].ptr, &a, &a, &a);
}

void	sp_pos(void)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < g_game.map.w)
	{
		j = 0;
		while (j < g_game.map.h)
		{
			if (g_game.map.map[j][i] == '2')
			{
				g_sp[k].s.x = j * TILE_SIZE + TILE_SIZE / 2;
				g_sp[k].s.y = i * TILE_SIZE + TILE_SIZE / 2;
				g_game.sp_num++;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	update_sp_d(void)
{
	int		i;
	int		j;
	t_sp	ech;

	i = -1;
	while (++i < g_game.sp_num)
		g_sp[i].dist = distance(g_sp[i].s.x, g_sp[i].s.y, g_player.pos.x, g_player.pos.y);
	i = 0;
	while (i < g_game.sp_num)
	{
		j = 0;
		while (j < g_game.sp_num - i)
		{
			if (g_sp[j].dist < g_sp[j + 1].dist)
			{
				ech = g_sp[j];
				g_sp[j] = g_sp[j + 1];
				g_sp[j + 1] = ech;
			}
			j++;
		}
		i++;
	}
}

void	render_sp(int x, int y, int sp_size, int k)
{
	int color;
	int i;
	int j;
	int ws;
	int hs;

	init_sprite(k, &ws, &hs);
	i = -1;
	while (++i < sp_size)
	{
		if (x + i < 0 || x + i > g_game.win_w)
			continue;
		if (g_sp[k].dist >= g_ray[x + i].dist)
			continue;
		j = -1;
		while (++j < sp_size)
		{
			color = g_sp[k].data[ws * (j * hs / sp_size) + (i * ws / sp_size)];
			if (color != 0)
				if (((x + i) >= 0 && (x + i) < g_game.win_w) && ((y + j) >= 0 && (y + j) < g_game.win_h))
					my_mlx_pixel_put(x + i, y + j, color);
		}
	}
}

void	sprites(void)
{
	float	sp_angle;
	float	sp_size;
	float	x;
	float	y;
	int		k;

	k = -1;
	while (++k < g_game.sp_num)
	{
		sp_angle = atan2(g_sp[k].s.y - g_player.pos.y, g_sp[k].s.x - g_player.pos.x) - g_player.rot_angle;
		while (sp_angle > M_PI)
			sp_angle -= 2 * M_PI;
		while (sp_angle < -M_PI)
			sp_angle += 2 * M_PI;
		if (g_game.win_h > g_game.win_w)
			sp_size = (g_game.win_h / g_sp[k].dist) * TILE_SIZE;
		else
			sp_size = (g_game.win_w / g_sp[k].dist) * TILE_SIZE;
		y = g_game.win_h / 2 - sp_size / 2;
		x = sp_angle * (g_game.win_w / FOV) + (g_game.win_w / 2 - sp_size / 2);
		render_sp(x, y, sp_size, k);
	}
}
