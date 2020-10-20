#include "../include/cub3d.h"

void render_map(void)
{
    int i;
    int j;
    t_rec rec;
    
    rec.size.x = MINI_MAP_SCALE * TILE_SIZE;
    rec.size.y = MINI_MAP_SCALE * TILE_SIZE;
    i = 0;
    while(i < g_game.map.w)
    {
        j = 0;
        while(j < g_game.map.h)
        {
            if (g_game.map.map[j][i] == '1' || g_game.map.map[j][i] == ' ')
                rec.color = 0;
            else if (g_game.map.map[j][i] == '0')
                rec.color = 0xFFFFFF;
            rec.pos.x = MINI_MAP_SCALE * i * TILE_SIZE;
            rec.pos.y = MINI_MAP_SCALE * j * TILE_SIZE;

            rect(rec);
            j++;
        }
        i++;               
    }
}

void render_rays()
{
    int i = 0;
    t_line l;

    l.pos.x = MINI_MAP_SCALE * g_player.pos.x;
    l.pos.y = MINI_MAP_SCALE * g_player.pos.y;
    while (i < g_game.win_w)
    {
        l.alpha = g_ray[i].angle;
        l.dist = MINI_MAP_SCALE * g_ray[i].dist;
        l.color = 0x8FFF0000;
        line(l);
        i++;
    }
}