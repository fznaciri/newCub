#include "../include/cub3d.h"

void write_exit(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*to_find;

	str = (char*)haystack;
	to_find = (char*)needle;
	if (to_find[0] == '\0')
		return ((char*)haystack);
	i = 0;
	j = 0;
	while (str[i + j] != '\0' && i < len)
	{
		while (str[i + j] == to_find[j] && i + j < len)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char*)haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}

int		ft_atoi(const char *str)
{
	int		i;
	int		signe;
	size_t	n;

	i = 0;
	signe = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			signe = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		n = n * 10 + str[i] - 48;
		if (n > 9223372036854775807)
			return ((signe > 0) ? -1 : 0);
		i++;
	}
	return ((int)(n * signe));
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	cdst = (unsigned char*)dst;
	csrc = (unsigned char*)src;
	i = 0;
	if (cdst == csrc)
		return (cdst);
	if (!cdst && !csrc)
		return (NULL);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char*)malloc((ft_strlen(s1) * sizeof(char)) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s1[i];
	return (str);
}

int bigger(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int spaces(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

void skip_spaces(char **s)
{
	while (**s == ' ' || **s == '\t')
		(*s)++;
}

void	skip_digit(char **s)
{
	while (ft_isdigit(**s))
		(*s)++;
}


int     is_wall_at(t_pos pos)
{   
	int index_x;
    int index_y;

    if (pos.x < 0 || pos.x > g_game.map.w * TILE_SIZE || pos.y < 0 || pos.y > g_game.map.h * TILE_SIZE)
        return TRUE;
    index_x = floor(pos.x / TILE_SIZE);
    index_y = floor(pos.y / TILE_SIZE);
	if (g_player.walk_dir == 1 && g_player.rot_angle >= M_PI && g_player.rot_angle <= 2 * M_PI)
       index_y = (floor((pos.y - 1)) / TILE_SIZE);
    if (g_player.walk_dir == 1 && g_player.rot_angle >= M_PI / 2 && g_player.rot_angle <= 1.5 * M_PI)
        index_x = (floor((pos.x - 1)) / TILE_SIZE);
    return (g_game.map.map[index_y][index_x] == '1' ? 1 : 0);
}

int is_wall(float x, float y)
{
	int index_x;
    int index_y;

    if (x < 0 || x > g_game.map.w * TILE_SIZE || y < 0 || y > g_game.map.h * TILE_SIZE)
        return TRUE;
    index_x = floor(x / TILE_SIZE);
    index_y = floor(y / TILE_SIZE);
    return (g_game.map.map[index_y][index_x] == '1' ? 1 : 0);
}

int     is_sp(float x, float y)
{   
	int index_x;
    int index_y;

	if (x < 0 || x > g_game.map.w * TILE_SIZE || y < 0 || y > g_game.map.h * TILE_SIZE)
        return TRUE;
    index_x = floor(x / TILE_SIZE);
    index_y = floor(y / TILE_SIZE);
    return (g_game.map.map[index_y][index_x] == '2' ? 1 : 0);
}

int     is_sp_at(t_pos pos)
{   
	int index_x;
    int index_y;

	if (pos.x < 0 || pos.x > g_game.map.w * TILE_SIZE || pos.y < 0 || pos.y > g_game.map.h * TILE_SIZE)
        return TRUE;
    index_x = floor(pos.x / TILE_SIZE);
    index_y = floor(pos.y / TILE_SIZE);
    return (g_game.map.map[index_y][index_x] == '2' ? 1 : 0);
}

float normalize_angle(float angle)
{
    angle = remainderf(angle, 2 * M_PI);
    if (angle < 0)
         angle += 2 * M_PI; 
    return (angle);
}

float distance(float x1, float y1, float x2, float y2)
{
    return (hypotf((x2 - x1), (y2 - y1)));
}

t_pos    copy_pos(t_pos *pos, t_pos s)
{
    pos->x = s.x;
    pos->y = s.y;
    return *pos;
}

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	int			i;

	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	i = 0;
	while (cs2[i] && cs1[i])
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (cs1[i] - cs2[i]);
}

void free_text()
{
	int i;

	i = -1;
	while (i++ < 4)
		free(g_tex[i].path);
	free(g_game.s_path);
}