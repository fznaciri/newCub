/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:15:22 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 10:14:09 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "structs.h"
# include "parser.h"
# include "utils.h"
# include "../malloc.h"

# define N_NO  0
# define N_WE  1
# define N_EA  2
# define N_SO  3
# define TILE_SIZE 64
# define MAX_INT 2147483647
# define FOV (60 * (M_PI / 180))
# define SPEED 8
# define ROT_SPEED SPEED * (M_PI / 180)
# define FALSE 0
# define TRUE 1
# define EVENT_EXIT 17
# define EVENT_KEYDOWN 2
# define EVENT_KEYUP 3

t_game		g_game;
t_img		g_img;
t_player	g_player;
t_tkn		g_tkn;
t_ray		*g_ray;
t_inter		g_horz;
t_inter		g_vert;
t_tex		g_tex[4];
t_sp		*g_sp;
t_wall		g_wall;

void		clear_image(void);
int			main_loop(void);
void		update();
void		render();
void		initialize_window(void);
void		load_texture(t_tex *tex);
void		init_sprite(int k, int *ws, int *hs);
void		setup(void);
int			key_down(int key);
int			key_up(int key);
int			destroy_window(void);
void		process_input(void);
void		move_player(void);
int			is_wall_at(t_pos pos);
int			is_wall(float x, float y);
int			is_sp_at(t_pos pos);
int			is_sp(float x, float y);
void		init_vert(int id);
void		init_horz(int id);
void		cast_vert(int id);
void		cast_horz(int id);
void		cast_ray(int i);
void		cast_allrays(void);
void		my_mlx_pixel_put(int x, int y, int color);
void		rect(t_rec rec);
void		line(t_line l);
int			get_text_color(t_tex tex, int x, int y);
void		set_text();
int			texture(int i);
void		init_wall(int i);
void		ceeling(int i);
void		wall(int i);
void		ground(int i);
void		render_3dwall();
void		sp_count();
void		sp_pos(void);
void		update_sp(void);
void		render_sp(int x, int y, int sp_size, int k);
void		sprites(void);
void		save();
void		int_in_char(unsigned char *str, int value);
int			write_header(int fd, unsigned int size);
int			write_data(int fd, unsigned int pad_br);
void		screen_shot(void);
void		free_text();
void		exit_error(int id, char *s);
void		free_map();
void		write_exit(char *s);

#endif
