/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:14:48 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/07 11:27:33 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = g_img.addr + (y * g_img.length + x * (g_img.bpp / 8));
	*((unsigned int*)dst) = color;
}

void	rect(t_rec rec)
{
	float i;
	float j;
	float k;

	j = 0;
	k = rec.pos.x;
	while (j < rec.size.y)
	{
		i = 0;
		while (i < rec.size.x)
		{
			my_mlx_pixel_put(k++, rec.pos.y, rec.color);
			i++;
		}
		k = rec.pos.x;
		rec.pos.y++;
		j++;
	}
}

void	line(t_line l)
{
	int i;
	int new_x;
	int new_y;

	i = 0;
	while (i < l.dist)
	{
		new_x = l.pos.x + cos(l.alpha) * i;
		new_y = l.pos.y + sin(l.alpha) * i;
		my_mlx_pixel_put(new_x, new_y, l.color);
		i++;
	}
}
