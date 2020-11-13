/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:52:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/13 20:38:22 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	tozero_tkn(void)
{
	g_tkn.map = 0;
	g_tkn.no = 0;
	g_tkn.so = 0;
	g_tkn.we = 0;
	g_tkn.ea = 0;
	g_tkn.s = 0;
	g_tkn.f = 0;
	g_tkn.c = 0;
	g_tkn.r = 0;
	g_tkn.l = 0;
}

void	treat_element(char *element)
{
	int i;

	i = spaces(element);
	if (element[i] == 'N' && element[i + 1] == 'O')
		treat_no(element + 2 + i);
	else if (element[i] == 'S' && element[i + 1] == 'O')
		treat_so(element + 2 + i);
	else if (element[i] == 'W' && element[i + 1] == 'E')
		treat_we(element + 2 + i);
	else if (element[i] == 'E' && element[i + 1] == 'A')
		treat_ea(element + 2 + i);
	else if (element[i] == 'R')
		treat_r(element + 1 + i);
	else if (element[i] == 'S')
		treat_s(element + 1 + i);
	else if (element[i] == 'F')
		treat_f(element + 1 + i);
	else if (element[i] == 'C')
		treat_c(element + 1 + i);
	else if (is_map(*element) && !(element[i] == 0 && g_tkn.map == 0))
		treat_m(element);
	else
		load_error("Error\n<cub> file isn't well defined");
}

void	load_file(char *path)
{
	int		r;

	tozero_tkn();
	if (!ft_strnstr(path, ".cub", ft_strlen(path)))
		write_exit("Error\nThe filetype isn't <cub>");
	if ((g_file.fd = open(path, O_RDONLY)) == -1)
		load_error("Error\nFile doesn't exist");
	g_game.map.map = 0;
	while ((r = gnl(g_file.fd, &g_file.line)) >= 0)
	{
		if (!empty_line(g_file.line))
			treat_element(g_file.line);
		free(g_file.line);
		if (r == 0)
			break ;
	}
	close(g_file.fd);
	g_tkn.l = 1;
	adjust_map();
	verify_map();
	verify_player();
	get_player();
}

int		empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	if (g_tkn.map == 1)
		return (0);
	return (1);
}
