#ifndef CUB3D_H
# define CUB3D_H
#include "mlx.h"
#include "setting/setting.h"
#include "game/game.h"
#include "texture/texture.h"
#include "gnl/gnl.h"
#include "utils/utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define TILE_SIZE 64
# define SCALE 0.2
# define MAX_INT 2147483647

int     key_down(int key, t_game *game);
int     key_up(int key, t_game *game);
int     exit_game(t_game *game);
void    render(t_game *game);
void    update(t_game *game);
int     main_loop(t_game *game);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    draw_rect(t_game *game, t_rec rec);
void    draw_line(t_game *game, t_line line);
void    draw_cercle(t_game *game, t_cercle cercle);
void    render_map(t_game *game);
void    render_player(t_game *game);
void    setup(t_game *game);
t_pos    copy_pos(t_pos *d, t_pos s);
t_pos   set_pos(t_pos *pos, float x, float y);
int     hit_wall(t_game *game, t_pos pos);
void    move_player(t_game *game);
void    cast_all_rays(t_game *game);
void    cast_ray(t_game *game, int id);
void    render_rays(t_game *game);
float   normalize_angle(float angle);
float   distance(float x1, float y1, float x2, float y2);
void    wall(t_game *game);

void    set_text(t_game *game);
int  get_text_color(t_text text, int x, int y);
void load_texture(t_game *game);
int     get_texture(t_game *game, int i);
int    load(t_game *game, char *path);

int     load_resolution(t_game *game, char *line);
int     load_cf_color(char *line);
int    load_text_no(t_game *game, char *line);
int    load_text_so(t_game *game, char *line);
int    load_text_we(t_game *game, char *line);
int    load_text_ea(t_game *game, char *line);
int     ft_chek_inrang(int n, int min, int max);
int		rgbtoint(int r, int g, int b);
#endif