#include "../include/cub3d.h"

void init_inter(t_inter *inter)
{   
    inter ->hit = FALSE;
    inter ->wall.x = 0;
    inter ->wall.y = 0;
}

void    hor_inter(t_inter *horz, int i)
{
    t_pos step;
    t_pos inter;

    step.y = TILE_SIZE;
    step.y *= (g_ray[i].ray_d ? 1 : -1);
    step.x = step.y / tan(g_ray[i].angle);
    inter.y = floor(g_player.pos.y / TILE_SIZE) * TILE_SIZE;
    inter.y += (g_ray[i].ray_d ? TILE_SIZE : 0);
    inter.y += (g_ray[i].ray_up ? -1 : 0); // make it part of the bloc above the line 
    inter.x = g_player.pos.x + ((inter.y - g_player.pos.y) / tan(g_ray[i].angle));
    horz ->next.x = inter.x;
    horz ->next.y = inter.y;
    while ((horz ->next.x > 0 && horz ->next.x < g_game.win_w) && (horz ->next.y > 0 && horz ->next.y < g_game.win_h))
    {
        if (is_wall_at(horz ->next))
        {
            horz ->hit = TRUE;
            horz ->wall.x = horz->next.x;
            horz->wall.y = horz->next.y;
            break;
        }
        else
        {
            horz ->next.x += step.x;
            horz ->next.y += step.y;
        }
    }
    horz ->dist = horz ->hit ? distance(g_player.pos.x, g_player.pos.y, horz ->wall.x, horz ->wall.y) : MAX_INT;
}

void    ver_inter(t_inter *vert, int i)
{
    t_pos step;
    t_pos inter;

    step.x = TILE_SIZE;
    step.x *= (g_ray[i].ray_l ? -1 : 1);
    step.y = step.y * tan(g_ray[i].angle);

    inter.x = floor(g_player.pos.x / TILE_SIZE) * TILE_SIZE;
    inter.x += (g_ray[i].ray_r ? TILE_SIZE : 0);
    inter.x += (g_ray[i].ray_l ? -1 : 0);
    inter.y = g_player.pos.y + ((inter.x - g_player.pos.x) * tan(g_ray[i].angle));
    vert ->next.x = inter.x;
    vert ->next.y = inter.y;
    while ((vert ->next.x > 0 && vert ->next.x < g_game.win_w) && (vert ->next.y > 0 && vert ->next.y < g_game.win_h))
    {
        if (is_wall_at(vert ->next))
        {
            vert ->hit = TRUE;
            vert ->wall.x = vert ->next.x;
            vert ->wall.y = vert ->next.y;
            break;
        }
        else
        {
            vert ->next.x += step.x;
            vert ->next.y += step.y;
        }
    }
    vert ->dist = vert ->hit ? distance(g_player.pos.x, g_player.pos.y, vert ->wall.x, vert ->wall.y) : MAX_INT;
}

void ray_fill(t_inter *horz, t_inter *vert, int i)
{
    if (vert->dist < horz ->dist)
    {
        g_ray[i].dist = vert ->dist;
        g_ray[i].wall_hit.x = vert ->wall.x;
        g_ray[i].wall_hit.y = vert ->wall.yy;
        g_ray[i].vert_hit = TRUE;
    }
    else
    {
        g_ray[i].dist = horz ->dist;
        g_ray[i].wall_hit.x = horz ->wall.x;
        g_ray[i].wall_hit.y = horz ->wall.y;
        g_ray[i].vert_hit = FALSE;
    }
}

void cast_ray(float angle, int i)
{
    t_inter horz;
    t_inter vert;

    g_ray[i].angle = normalize_angle(angle);
    g_ray[i].ray_d = ((g_ray[i].angle > 0 && g_ray[i].angle < M_PI)? 1 : 0);
    g_ray[i].ray_up = !g_ray[i].ray_d;
    g_ray[i].ray_r = ((g_ray[i].angle < M_PI * 0.5 || g_ray[i].angle > 1.5 * M_PI) ? 1 : 0);
    g_ray[i].ray_l = !g_ray[i].ray_r;

    init_inter(&horz);
    init_inter(&vert);
    hor_inter(&horz, i);
    ver_inter(&vert, i);
    ray_fill(&horz, &vert, i);
}

void cast_allrays()
{
    int id = 0;
    float ray_angle = g_player.rotation_angle - (FOV / 2);
    while (id < g_game.win_w)
    {
        cast_ray(ray_angle, id);
        ray_angle += FOV / g_game.win_w;
        id++;
    }
}