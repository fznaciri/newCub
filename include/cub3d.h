#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include "mlx.h"

#define N_NO  0
#define N_WE  1
#define N_EA  2
#define N_SO  3

#define A_NO  0
#define A_WE  1
#define N_EA  2
#define N_SO  3

# define TILE_SIZE 64
# define MAX_INT 2147483647
# define FOV (60 * (M_PI / 180))

#define SPEED 8
#define ROT_SPEED 8 * (M_PI / 180)

#define FALSE 0
#define TRUE 1

# define EVENT_EXIT 17

#define IS_MAP_ELEMENT(x) (x == 'N' || x == 'W' || x == 'S' || x == 'E' || x == '2' || x == '1' || x == '0')
#define IS_ZSP(x) (x == 'N' || x == 'W' || x == 'S' || x == 'E' || x == '2')
#define IS_P(x) (x == 'N' || x == 'W' || x == 'S' || x == 'E')

typedef struct  s_img {
    void        *img;
    char        *addr;
    int         bpp;
    int         length;
    int         e;
}               t_img;

typedef struct	s_tkn
{
	char map;
	char no;
	char so;
	char we;
	char ea;
	char r;
	char s;
	char f;
	char c;
}				t_tkn;

typedef     struct s_color
{
    int     r;
    int     g;
    int     b;
}              t_color;


typedef struct s_pos
{
    float   x;
    float   y;
}   t_pos;


typedef struct  s_map
{
    char **map;
	int w;
	int h;
}               t_map;

typedef struct	s_sp
{
	void		*ptr;
	int			*data;
	t_pos       s;
	float		distance;
}				t_sp;

typedef struct  s_inter
{
    t_pos   next;
    int     hit;
    t_pos   wall;
    float   dist;
}               t_inter;

typedef struct  s_ray
{
    float   angle;
    t_pos   wall_hit;
    float   dist;
    int     vert_hit;
    int     ray_d;
    int     ray_up;
    int     ray_r;
    int     ray_l;
}               t_ray;


typedef struct s_tex
{
    t_img   tex;
    char    *path;
    int     w;
    int     h;
    //float   offset_x;
    //float   offset_y;
}       t_tex;

typedef struct s_player 
{
    t_pos pos;
    float rotation_angle;
    float move_speed;
    float angle_speed;
    int turn_direction;
    int walk_direction;
}   t_player;

typedef struct s_game
{
    // Minilibx
    void    *m_ptr;
    void    *w_ptr;
    // Map properties
	t_map   map;
	//	Textures
	t_tex   tex[4];
    // Sprites
    char    *s_path;
    t_sp    sp[100];
    int     sp_num;
	// Window resolution
	int win_w;
	int win_h;
	// Colors
	int floor;
	int ceeling;
}   t_game;



t_img       g_img;
t_player    g_player;
t_game      g_game;
t_tkn       g_tkn;
t_ray       *g_ray;


// Load file
void load_file(char *path);
void tozero_tkn();
// void treat_line(char *line);

void treat_element(char *element);
void treat_no(char *s);
void treat_so(char *s);
void treat_we(char *s);
void treat_ea(char *s);
void treat_s(char *s);
void treat_f(char *s);
void treat_c(char *s);
void treat_r(char *s);
void check_before_map();
void treat_m(char *element);
int empty_line(char *line);
void fill_spaces(char *str, int s, int e);
void adjust_map();
void verify_map();
void verify_player();
void get_player();


void    initialize_window();
int     destroy_window();
void    setup();
void    process_input();
int     main_loop();
void    init_inter(t_inter *inter);
void    hor_inter(t_inter *horz, int i);
void    ver_inter(t_inter *vert, int i);
void    ray_fill(t_inter *horz, t_inter *vert);
void    cast_ray(float angle, int i);
void    cast_allrays();



// Utils
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
void    write_exit(char *s);
int     bigger(int a, int b);
void    skip_spaces(char **s);
int     spaces(char *s);
void	skip_digit(char **s);
int     is_wall_at(t_pos pos);
float normalize_angle(float angle);
float distance(float x1, float y1, float x2, float y2);


int		gnl(int fd, char **line);

#endif