#include "../include/cub3d.h"

void move_player(void)
{
    float step;
    t_pos new;
    
    step = g_player.walk_dir * SPEED;
    g_player.rot_angle += g_player.turn_dir * ROT_SPEED;
    new.x = (g_player.pos.x + step * cos(g_player.rot_angle));
    new.y = (g_player.pos.y + step * sin(g_player.rot_angle)); 
    if (!is_wall_at(new) && !is_sp_at(new))
    {
        g_player.pos.x = new.x;
        g_player.pos.y = new.y; 
    }
}

void render_player(void)
{
    t_rec rec;
    t_line l;
    int player_size;

    player_size = 2;
    rec.pos.x = MINI_MAP_SCALE * g_player.pos.x;
    rec.pos.y = MINI_MAP_SCALE * g_player.pos.y;
    rec.size.x = MINI_MAP_SCALE * 2;
    rec.size.y = MINI_MAP_SCALE * 2;
    rec.color = 0x00FF00;
    rect(rec);
    l.pos.x = MINI_MAP_SCALE * (g_player.pos.x + (player_size / 2));
    l.pos.y = MINI_MAP_SCALE * (g_player.pos.y + (player_size / 2));
    l.alpha = g_player.rot_angle;
    l.dist = MINI_MAP_SCALE * 50;
    l.color = 0x00FF00;
    line(l);
}