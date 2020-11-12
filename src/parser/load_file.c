/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:52:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/10 10:04:14 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	tozero_tkn(void)
{
	g_tkn = (t_tkn){.map = 0, .no = 0, .so = 0, .we = 0, .ea = 0, .s = 0};
	g_tkn = (t_tkn){.f = 0, .c = 0, .r = 0};
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
	int		fd;
	char	*line;
	int		r;

	tozero_tkn();
	if (!ft_strnstr(path, ".cub", ft_strlen(path)))
		load_error("Error\nThe filetype isn't <cub>");
	if ((fd = open(path, O_RDONLY)) == -1)
		write_exit("Error\nFile doesn't exist");
	g_game.map.map = 0;
	while ((r = gnl(fd, &line)) >= 0)
	{
		if (!empty_line(line))
			treat_element(line);
		free(line);
		if (r == 0)
			break ;
	}
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
		if (line[i] != ' ' || line[i] != '\t')
			return (0);
	if (g_tkn.map == 1)
		load_error("Error\nMap should be the last Element in the <cub> file");
	return (1);
}
