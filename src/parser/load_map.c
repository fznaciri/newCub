/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:39:51 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/08 12:19:25 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_before_map(void)
{
	if (g_tkn.no == 0 || g_tkn.so == 0 || g_tkn.we == 0 || g_tkn.ea == 0
			|| g_tkn.s == 0 || g_tkn.f == 0 || g_tkn.c == 0 || g_tkn.r == 0)
		write_exit("Error\nMissing elements in <cub>  file");
}

void	treat_m(char *element)
{
	char **temp;

	if (g_game.map.map == NULL)
	{
		check_before_map();
		g_game.map.map = malloc(sizeof(char *));
		g_game.map.map[0] = ft_strdup(element);
		g_game.map.h = 1;
		g_game.map.w = ft_strlen(element);
		g_tkn.map = 1;
	}
	else
	{
		temp = g_game.map.map;
		g_game.map.map = malloc((g_game.map.h + 1) * sizeof(char *));
		ft_memcpy(g_game.map.map, temp, sizeof(char *) * g_game.map.h);
		free(temp);
		g_game.map.map[g_game.map.h] = ft_strdup(element);
		g_game.map.h += 1;
		g_game.map.w = bigger(ft_strlen(element), g_game.map.w);
	}
}

void	adjust_map(void)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = malloc(g_game.map.h * sizeof(char *));
	while (i < g_game.map.h)
	{
		new[i] = malloc(g_game.map.w + 1);
		ft_memcpy(new[i], g_game.map.map[i], ft_strlen(g_game.map.map[i]));
		fill_spaces(new[i], ft_strlen(g_game.map.map[i]), g_game.map.w);
		i++;
	}
	i = 0;
	while (i < g_game.map.h)
		free(g_game.map.map[i++]);
	free(g_game.map.map);
	g_game.map.map = new;
}

void	verify_map(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	verify_border();
	while (++i < g_game.map.h - 1)
	{
		while (++j < g_game.map.w - 1)
		{
			if (is_zsp(g_game.map.map[i][j])
				&& (g_game.map.map[i - 1][j - 1] == ' '
				|| g_game.map.map[i - 1][j] == ' '
				|| g_game.map.map[i - 1][j + 1] == ' '
				|| g_game.map.map[i][j - 1] == ' '
				|| g_game.map.map[i][j + 1] == ' '
				|| g_game.map.map[i + 1][j - 1] == ' '
				|| g_game.map.map[i + 1][j] == ' '
				|| g_game.map.map[i + 1][j + 1] == ' '))
				write_exit("Error\nMap should be rounded by 1");
		}
		j = 0;
	}
}

void	verify_border(void)
{
	int i;

	i = 0;
	while (i < g_game.map.w)
	{
		if ((g_game.map.map[0][i] != '1' && g_game.map.map[0][i] != ' ')
				|| (g_game.map.map[g_game.map.h - 1][i] != '1'
					&& g_game.map.map[g_game.map.h - 1][i] != ' '))
			write_exit("Error\nIncorrect Map");
		i++;
	}
	i = 0;
	while (i < g_game.map.h)
	{
		if ((g_game.map.map[i][0] != '1' && g_game.map.map[i][0] != ' ')
				|| (g_game.map.map[i][g_game.map.w - 1] != '1'
					&& g_game.map.map[i][g_game.map.w - 1] != ' '))
			write_exit("Error\nIncorrect Map");
		i++;
	}
}
