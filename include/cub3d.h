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

# define TILE_SIZE 64
# define MAX_INT 2147483647
# define FOV (60 * (M_PI / 180))
# define MINI_MAP_SCALE 0.2

#define SPEED 8
#define ROT_SPEED 8 * (M_PI / 180)
#define WALL_WIDTH 1

#define FALSE 0
#define TRUE 1

# define EVENT_EXIT 17
# define EVENT_KEYDOWN 2
# define EVENT_KEYUP 3

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
	float		dist;
}				t_sp;

typedef struct  s_inter
{
    t_pos step;
    t_pos   inter;
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
    t_pos   pos;
    //float   offset_x;
    //float   offset_y;
}       t_tex;

typedef struct s_player 
{
    t_pos   pos;
    float   rot_angle;
    int     turn_dir;
    int     walk_dir;
}   t_player;

typedef struct s_rec
{
    t_pos pos;
    t_pos size;
    int   color;

}              t_rec;

typedef struct s_line
{
    t_pos pos;
    float alpha;
    int   dist;
    int   color;
}               t_line;

typedef struct s_game
{
    // Minilibx
    void    *m_ptr;
    void    *w_ptr;
    // Map properties
	t_map   map;
	//	Textures
	// t_tex   tex[4];
    // Sprites
    char    *s_path;
    int     sp_num;
	// Window resolution
	int win_w;
	int win_h;
	// Colors
	int floor;
	int ceeling;
}   t_game;



t_game      g_game;
t_img       g_img;

t_player    g_player;

t_tkn       g_tkn;

t_ray       *g_ray;
t_inter     g_horz;
t_inter     g_vert;

t_tex       g_tex[4];
t_sp        g_sp[100];

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

// game settings
void    initialize_window(void);
int     destroy_window(void);
void    setup(void);
void    process_input(void);
void    clear_image(void);
int     main_loop(void);

//ray casting
void    init_vert(int id);
void    init_horz(int id);
void    hor_inter(int i);
void    ver_inter(int i);
void    ray_fill(int i);
void    cast_ray(int i);
void    cast_allrays(void);
void    render_rays(void);
void    cast_vert(int id);
void    cast_horz(int id);

// drawing
void    my_mlx_pixel_put(int x, int y, int color);
void    rect(t_rec rec);
void    line(t_line l);

// events
int     key_down(int key);
int     key_up(int key);
void    move_player(void);

// rendering minimap
void    render_player(void);
void    render_map(void);

//loading textures
void load_texture(t_tex *tex);
int  get_text_color(t_tex tex, int x, int y);
void set_text();
t_pos    set_pos(t_pos *pos, float x, float y);
int texture(int i);
 
 // Renderimgs walls
 void   render_3dwall();
 void   render();
 void   update();

// Sprite
void	init_sprite(int k, int *ws, int *hs);
void	sp_pos(void);
void	update_sp_d(void);
void	render_sp(int x, int y, int sp_size, int k);
void	sprites(void);
int     is_sp_at(t_pos pos);

// game utils
int     is_wall_at(t_pos pos);
float   normalize_angle(float angle);
float   distance(float x1, float y1, float x2, float y2);
t_pos    copy_pos(t_pos *pos, t_pos s);

// save
void	save();
void	int_in_char(unsigned char *str, int value);
int		write_header(int fd, unsigned int size);
int		write_data(int fd, unsigned int pad_br);
void	screen_shot(void);
int		ft_strcmp(const char *s1, const char *s2);

// Utils loading file
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
int		gnl(int fd, char **line);

#endif