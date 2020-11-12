/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:45:16 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/10 10:01:38 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	treat_r(char *s)
{
	int i;

	i = 0;
	skip_spaces(&s);
	g_game.win_w = ft_atoi(s);
	skip_digit(&s);
	skip_spaces(&s);
	if (!ft_isdigit(*s))
		load_error("Error\nNo value assigned to R element");
	g_game.win_h = ft_atoi(s);
	skip_digit(&s);
	skip_spaces(&s);
	if (*s)
		load_error("Error\nNo value assigned to R element");
	g_tkn.r += 1;
	if (g_tkn.r == 2)
		load_error("Error\nMore  than one R detected in <cub> file");
	if (g_game.win_h <= 0 || g_game.win_w <= 0)
		load_error("Error\nNo value assigned to R element");
	g_game.win_w = g_game.win_w > 2560 ? 2560 : g_game.win_w;
	g_game.win_h = g_game.win_h > 1440 ? 1440 : g_game.win_h;
}
