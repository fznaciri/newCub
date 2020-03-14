#ifndef SETTING_H
#define SETTING_H
#include "keys.h"

#define FOV (60 * M_PI / 180)
#define WALL_WIDTH 1
#define WIDTH_WIN 1920
#define HEIGHT_WIN 1080

typedef struct s_map
{
    char    **map;
    int     row;
}   t_map;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}    t_data;
typedef struct s_pos
{
    float   x;
    float   y;
}    t_pos;

typedef struct s_rec
{
    t_pos pos;
    t_pos size;
    int color;
} t_rec;

typedef struct s_line
{
    t_pos pos;
    float alpha;
    float   d;
    int color;
}   t_line;

typedef struct s_cercle
{
    t_pos pos;
    float   r;
    int color;
}   t_cercle;

typedef struct  s_ray
{
    t_pos   pos;
    float   angle;
    float   wall_hitx;
    float   wall_hity;
    float   distance;
    int     wall_hitcontent;
    int     vertical_hit;
    int     facing_down;
    int     facing_up;
    int     facing_right;
    int     facing_left;
}   t_ray;

typedef struct  s_setting
{
    void        *m_ptr;
    void        *w_ptr;
    char        *title;
    t_pos       r;
}   t_setting;




#endif