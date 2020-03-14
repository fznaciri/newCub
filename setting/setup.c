#include "../cub3d.h"

int    load(t_game *game, char *path)
{
    int fd;
    char *line;
    int n;
    int error;
    COLOR color;

    game->text = malloc(sizeof(t_text) * 5);
    game->map.map = malloc(sizeof(char*) * 1);
    game->map.row = 0;
    n = 0;
    error = 0;
    fd = open(path, O_RDONLY);
    while ((n = gnl(fd, &line)) >= 0)
    {
        skip(&line, ' ');
        if (*line == 'R')
        {
            error = load_resolution(game, line);
            if (error)
                return -1;
        }
        else if (*line == 'C')
        {
            color = load_cf_color(line);
            if (color < 0)
                return -1;
            else
                game->celling = color;
        }
        else if (*line == 'F')
        {
            color = load_cf_color(line);
            if (color < 0)
                return -1;
            else
                game->floor = color;
        }
        else if (*line == 'N' && *(line + 1) == 'O')
        {
            error = load_text_no(game, line);
            if (error)
                return -1;
        }
        else if (*line == 'S' && *(line + 1) == 'O')
        {
             error = load_text_so(game, line);
            if (error)
                return -1;
        }
        else if (*line == 'W' && *(line + 1) == 'E')
        {
             error = load_text_we(game, line);
            if (error)
                return -1;
        }
        else if (*line == 'E' && *(line + 1) == 'A')
        {
            error = load_text_ea(game, line);
            if (error)
                return -1;
        }
        else if (*line == 'S')
        {
            error = load_sprit(game, line);
            if (error)
                return -1;
        }
        if (!n || find_map(line))
            break;
        free(line);
    }
    load_map(game, line);
    while ((n = gnl(fd, &line)) >= 0)
    {
        load_map(game, line);
        free(line);
        if (!n)
            break;
    }
    if (error > 0)
        return -1;
    return 0;

}
int     find_map(char *line)
{
    int i;
    
    i = 0;
    while(line[i] != '\0')
    {
        while (line[i] == ' ')
            i++;
        if (line[i] == '1')
            return 1;
    }
    return 0;
}
int    load_map(t_game *game, char *line)
{
    game->map.map = ft_realalloc(game->map.map, game->map.row, game->map.row + 1);
    game->map.map[game->map.row] = line;
    game->map.row++;
    return 0;
}

int    load_text_no(t_game *game, char *line)
{
    line++;
    line++;
    skip(&line, ' ');
    if (*line == '\0')
        return 1;
    game->text[T_N].path = ft_strdup(line);
    return 0;
}

int    load_text_so(t_game *game, char *line)
{
    line++;
    line++;
    skip(&line, ' ');
    if (*line == '\0')
        return 1;
    game->text[T_S].path = ft_strdup(line);
    return 0;
}

int    load_text_we(t_game *game, char *line)
{
    line++;
    line++;
    skip(&line, ' ');
    if (*line == '\0')
        return 1;
    game->text[T_W].path = ft_strdup(line);
    return 0;
}

int    load_text_ea(t_game *game, char *line)
{
    line++;
    line++;
    skip(&line, ' ');
    if (*line == '\0')
        return 1;
    game->text[T_E].path = ft_strdup(line);
    return 0;
}

int    load_resolution(t_game *game, char *line)
{
    line++;
    skip(&line, ' ');
    if (ft_isdigit(*line))
        game->res.x = ft_atoi(line);
    else
        return 1;
    while (ft_isdigit(*line))
        line++;
    skip(&line, ' ');
    if (ft_isdigit(*line))
        game->res.y = ft_atoi(line);
    else
        return 1;
    while(ft_isdigit(*line) || *line == ' ')
        line++;
    if (*line != '\0')
        return 1;
    return 0;
}

int    load_cf_color(char *line)
{
    int r;
    int g;
    int b;

    line++;
    while (*line == ' ')
        line++;
    if (ft_isdigit(*line))
        r = ft_atoi(line);
    else
        return -1;
    while (*line == ' ' || ft_isdigit(*line))
        line++;
    if (*line != ',')
        return -1;
    line++;
    if (ft_isdigit(*line))
        g = ft_atoi(line);
    else
        return -1;
     while (*line == ' ' || ft_isdigit(*line))
        line++;
    if (*line != ',')
       return -1;
    line++;
    if (ft_isdigit(*line))
        b = ft_atoi(line);
    else
        return -1;
    if (!ft_chek_inrang(r, 0, 255) && !ft_chek_inrang(g, 0, 255) && !ft_chek_inrang(b, 0, 255))
        return -1;
    return rgbtoint(r,g,b);
}

int    load_sprit(t_game *game, char *line)
{
    line++;
    line++;
    skip(&line, ' ');
    if (*line == '\0')
        return 1;
    game->text[S].path = ft_strdup(line);
    return 0;
}

int     ft_chek_inrang(int n, int min, int max)
{
    if (n <= max && n >= min)
        return 1;
    return 0;
}

int		rgbtoint(int r, int g, int b)
{
	return ((r * pow(256, 2)) + (g * 256) + b);
}

void    skip(char **line, char c)
{
     while (**line == c)
        (*line)++;
}