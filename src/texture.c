/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:51:21 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/07 12:02:16 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		get_text_color(t_tex tex, int x, int y)
{
	if (x >= 0 && x < tex.w && y >= 0 && y < tex.h)
	{
		return (*((unsigned int*)tex.tex.addr + (y * tex.w + x)));
	}
	return (0);
}

void	set_text(void)
{
	int i;

	i = 0;
	while (i < 4)
	{
		g_tex[i].w = 64;
		g_tex[i].h = 64;
		i++;
	}
	load_texture(&g_tex[N_NO]);
	load_texture(&g_tex[N_SO]);
	load_texture(&g_tex[N_WE]);
	load_texture(&g_tex[N_EA]);
}

int		texture(int i)
{
	if (!g_ray[i].vert_hit)
		return (g_ray[i].ray_d ? N_SO : N_NO);
	else
		return (g_ray[i].ray_l ? N_WE : N_EA);
}
