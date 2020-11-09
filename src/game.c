/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:30:30 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 14:13:38 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	clear_image(void)
{
	t_rec rec;

	rec.pos.x = 0;
	rec.pos.y = 0;
	rec.size.x = g_game.win_w;
	rec.size.y = g_game.win_h;
	rec.color = 0x000000;
	rect(rec);
}

void	update(void)
{
	move_player();
	cast_allrays();
	update_sp();
}

void	render(void)
{
	render_3dwall();
	sprites();
}

int		main_loop(void)
{
	clear_image();
	update();
	render();
	mlx_put_image_to_window(g_game.m_ptr, g_game.w_ptr, g_img.img, 0, 0);
	return (0);
}
