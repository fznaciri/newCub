#include "../include/cub3d.h"

void tozero_tkn()
{
	g_tkn = (t_tkn){.map = 0, .no = 0, .so = 0, .we = 0, .ea = 0, .s = 0};
	g_tkn = (t_tkn){.f = 0, .c = 0, .r = 0};
}

void treat_element(char *element)
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
	else if (IS_MAP_ELEMENT(element[i]))
		treat_m(element);
	else
		write_exit("Error\n<cub> file isn't well defined");
}

void treat_no(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to NO element");
	g_tex[N_NO].path = ft_strdup(s);
	g_tkn.no += 1;
	if (g_tkn.no == 2)
		write_exit("Error\nMore than one NO detected in <cub> file");
}

void treat_so(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to SO element");
	g_tex[N_SO].path = ft_strdup(s);
	g_tkn.so += 1;
    if (g_tkn.so == 2)
		write_exit("Error\nMore than one SO detected in <cub> file");
}

void treat_we(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to WE element");
	g_tex[N_WE].path = ft_strdup(s);
	g_tkn.we += 1;
	if (g_tkn.we == 2)
		write_exit("Error\nMore than one WE detected in <cub> file");
}

void treat_ea(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to EA element");
	g_tex[N_EA].path = ft_strdup(s);
	g_tkn.ea += 1;
	if (g_tkn.ea == 2)
		write_exit("Error\nMore than one EA detected in <cub> file");
}

void treat_s(char *s)
{
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to S element");
	g_game.s_path = ft_strdup(s);
	g_tkn.s += 1;
	if (g_tkn.s == 2)
		write_exit("Error\nMore than one S detected in <cub> file");
}

void treat_f(char *s)
{
	t_color	color;
	
	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to F element");
	color.r = ft_atoi(s);
	skip_digit(&s);
	skip_spaces(&s);
	s++;
	color.g = ft_atoi(s);
	skip_digit(&s);
	skip_spaces(&s);
	s++;
	color.b = ft_atoi(s);
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255 || color.b < 0 || color.b > 255)
		write_exit("Error\nColors are invalid");
	color.r <<= 16;
	color.g <<= 8;
	g_game.floor = color.r + color.g + color.b;
	g_tkn.f += 1;
	if (g_tkn.f == 2)
		write_exit("Error\nMore than one F detected in <cub> file");
}

void treat_c(char *s)
{
	t_color color;

	skip_spaces(&s);
	if (!*s)
		write_exit("Error\nNo value assigned to C element");
	color.r = ft_atoi(s);
	skip_digit(&s);
	skip_spaces(&s);
	s++;
	color.g = ft_atoi(s);
	skip_digit(&s);
	skip_spaces(&s);
	s++;
	color.b = ft_atoi(s);
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255 || color.b < 0 || color.b > 255)
		write_exit("Error\nColors are invalid");
	color.r <<= 16;
	color.g <<= 8;
	g_game.ceeling = color.r + color.g + color.b;
	g_tkn.c += 1;
	if (g_tkn.c == 2)
		write_exit("Error\nMore than one C detected in <cub> file");
}

void treat_r(char *s)
{
	int i;

	i = 0;
	skip_spaces(&s);
	g_game.win_w = ft_atoi(s);
	skip_digit(&s);
	skip_spaces(&s);
	g_game.win_h = ft_atoi(s);
	g_tkn.r += 1;
	if (g_tkn.r == 2)
		write_exit("Error\nMore  than one R detected in <cub> file");
	if (g_game.win_h <= 0 || g_game.win_w <= 0)
		write_exit("Error\nResolution is invalid");
	g_game.win_w = g_game.win_w > 2560 ? 2560 : g_game.win_w;
	g_game.win_h = g_game.win_h > 1440 ? 1440 : g_game.win_h;
}

void check_before_map()
{
	if (g_tkn.no == 0 || g_tkn.so == 0 || g_tkn.we == 0 || g_tkn.ea == 0 || g_tkn.s == 0
			|| g_tkn.f == 0 || g_tkn.c == 0)
		write_exit("Error\nNot all elements defined above the map in <cub> file");
}

void treat_m(char *element)
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

int empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
		if (line[i] != ' ' || line[i] != '\t')
			return (0);
	if (g_tkn.map == 1)
		write_exit("Error\nMap should be the last Element in the <cub> file");
	return (1);
}

void fill_spaces(char *str, int s, int e)
{
	int i;

	i = s;
	while (i < e)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = 0;
}

void adjust_map()
{
	int i;
	int j;
	char **new;

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

void verify_map()
{
	int i;
	int j;
	
	i = 0;
	while (i < g_game.map.w)
	{
		if ((g_game.map.map[0][i] != '1' && g_game.map.map[0][i] != ' ') ||
				(g_game.map.map[g_game.map.h - 1][i] != '1' && g_game.map.map[g_game.map.h - 1][i] != ' '))
			write_exit("Error\nIncorrect Map");
		i++;
	}
	i = 0;
	while (i < g_game.map.h)
	{
		if ((g_game.map.map[i][0] != '1' && g_game.map.map[i][0] != ' ') || 
				(g_game.map.map[i][g_game.map.w - 1] != '1' && g_game.map.map[i][g_game.map.w - 1] != ' '))
			write_exit("Error\nIncorrect Map");
		i++;
	}
	i = 1;
	j = 1;
	while (i < g_game.map.h - 1)
	{
		while (j < g_game.map.w - 1)
		{
			if (IS_ZSP(g_game.map.map[i][j]) && (g_game.map.map[i - 1][j - 1] == ' ' || g_game.map.map[i - 1][j] == ' ' || g_game.map.map[i - 1][j + 1] == ' '
						|| g_game.map.map[i][j - 1] == ' ' || g_game.map.map[i][j + 1] == ' ' || g_game.map.map[i + 1][j - 1] == ' ' 
						|| g_game.map.map[i + 1][j] == ' ' || g_game.map.map[i + 1][j + 1] == ' '))
				write_exit("Error\nMap should be rounded by 1");
			j++;
		}
		j = 0;
		i++;
	}
}

void verify_player()
{
	int i;
	int j;
	int nop;

	i = 0;
	j = 0;
	nop = 0;
	while (i < g_game.map.h)
	{
		while (j < g_game.map.w)
		{
			if (IS_MAP_ELEMENT(g_game.map.map[i][j]) || g_game.map.map[i][j] == ' ')
			{
				if (IS_P(g_game.map.map[i][j]))
					nop++;
			}
			else
				write_exit("Error\nBad character in map");
			j++;
		}
		i++;
		j = 0;
	}
	if (nop == 0)
		write_exit("Error\nNo player detected in map");
	else if (nop > 1)
		write_exit("Error\nMore than one player detected in map");
}

void get_player()
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_game.map.h)
	{
		while (j < g_game.map.w)
		{
			if (IS_MAP_ELEMENT(g_game.map.map[i][j]) || g_game.map.map[i][j] == ' ')
			{
				if (IS_P(g_game.map.map[i][j]))
				{
					g_player.pos.x = j * TILE_SIZE;
					g_player.pos.y = i * TILE_SIZE;
					if (g_game.map.map[i][j] == 'S')
						g_player.rot_angle = M_PI / 2;
					if (g_game.map.map[i][j] == 'N')
						g_player.rot_angle = 3 * M_PI / 2;
					if (g_game.map.map[i][j] == 'W')
						g_player.rot_angle = M_PI;
					if (g_game.map.map[i][j] == 'E')
						g_player.rot_angle = 0;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void load_file(char *path)
{
	int fd;
	char *line;
	int r;

    if (!ft_strnstr(path, ".cub", ft_strlen(path)))
        write_exit("Error\nThe filetype isn't <cub>");
    if ((fd = open(path, O_RDONLY)) == -1)
		write_exit("Error\nFile doesn't exist");
	g_game.map.map = 0;
	while ( (r = gnl(fd, &line)) >= 0)
	{
		
		
		if (!empty_line(line))
			treat_element(line);
		free(line);
		if (r == 0)
			break;
	}
	adjust_map();
	verify_map();
	verify_player();
	get_player();
}