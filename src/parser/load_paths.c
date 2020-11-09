/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:34:45 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/07 13:42:01 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	treat_no(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to NO element");
	g_tex[N_NO].path = ft_strdup(s);
	g_tkn.no += 1;
	if (g_tkn.no == 2)
		write_exit("Error\nMore than one NO detected in <cub> file");
}

void	treat_so(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to SO element");
	g_tex[N_SO].path = ft_strdup(s);
	g_tkn.so += 1;
	if (g_tkn.so == 2)
		write_exit("Error\nMore than one SO detected in <cub> file");
}

void	treat_we(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to WE element");
	g_tex[N_WE].path = ft_strdup(s);
	g_tkn.we += 1;
	if (g_tkn.we == 2)
		write_exit("Error\nMore than one WE detected in <cub> file");
}

void	treat_ea(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to EA element");
	g_tex[N_EA].path = ft_strdup(s);
	g_tkn.ea += 1;
	if (g_tkn.ea == 2)
		write_exit("Error\nMore than one EA detected in <cub> file");
}

void	treat_s(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to S element");
	g_game.s_path = ft_strdup(s);
	g_tkn.s += 1;
	if (g_tkn.s == 2)
		write_exit("Error\nMore than one S detected in <cub> file");
}
