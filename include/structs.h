/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:48:52 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 10:23:17 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_pos
{
	float		x;
	float		y;
}				t_pos;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_tkn
{
	char		map;
	char		no;
	char		so;
	char		we;
	char		ea;
	char		r;
	char		s;
	char		f;
	char		c;
}				t_tkn;

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bpp;
	int			length;
	int			e;
}				t_img;

typedef struct	s_map
{
	char		**map;
	int			w;
	int			h;
}				t_map;

typedef struct	s_sp
{
	void		*ptr;
	int			*data;
	t_pos		s;
	float		dist;
}				t_sp;

typedef struct	s_inter
{
	t_pos		step;
	t_pos		inter;
	t_pos		next;
	int			hit;
	t_pos		wall;
	float		dist;
}				t_inter;

typedef struct	s_ray
{
	float		angle;
	t_pos		wall_hit;
	float		dist;
	int			vert_hit;
	int			ray_d;
	int			ray_up;
	int			ray_r;
	int			ray_l;
}				t_ray;

typedef struct	s_wall
{
	int			h;
	float		dist;
	int			top;
	int			bot;
	int			color;
	int			t;
	int			j;
}				t_wall;

typedef struct	s_tex
{
	t_img		tex;
	char		*path;
	int			w;
	int			h;
	t_pos		pos;
}				t_tex;

typedef struct	s_player
{
	t_pos		pos;
	float		rot_angle;
	int			turn_dir;
    int         x_walk;
	int			walk_dir;
}				t_player;

typedef struct	s_rec
{
	t_pos		pos;
	t_pos		size;
	int			color;

}				t_rec;

typedef struct	s_line
{
	t_pos		pos;
	float		alpha;
	int			dist;
	int			color;
}				t_line;

typedef struct	s_game
{
	void		*m_ptr;
	void		*w_ptr;
	t_map		map;
	char		*s_path;
	int			sp_num;
	int			win_w;
	int			win_h;
	int			floor;
	int			ceeling;
}				t_game;

#endif
