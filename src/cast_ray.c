#include "../include/cub3d.h"

void init_inter(t_inter inter)
{   
    inter.hit = FALSE;
    inter.wall.x = 0;
    inter.wall.y = 0;
}

void    hor_inter(int i)
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
    g_horz.next.x = inter.x;
    g_horz.next.y = inter.y;
    while ((g_horz.next.x > 0 && g_horz.next.x < g_game.win_w) && (g_horz.next.y > 0 && g_horz.next.y < g_game.win_h))
    {
        if (is_wall_at(g_horz.next))
        {
            g_horz.hit = TRUE;
            g_horz.wall.x = g_horz.next.x;
            g_horz.wall.y = g_horz.next.y;
            break;
        }
        else
        {
            g_horz.next.x += step.x;
            g_horz.next.y += step.y;
        }
    }
}

void    ver_inter(int i)
{
    t_pos step;
    t_pos inter;

    step.x = TILE_SIZE;
    step.x *= (g_ray[i].ray_l ? -1 : 1);
    step.y = step.x * tan(g_ray[i].angle);

    inter.x = floor(g_player.pos.x / TILE_SIZE) * TILE_SIZE;
    inter.x += (g_ray[i].ray_r ? TILE_SIZE : 0);
    inter.x += (g_ray[i].ray_l ? -1 : 0);
    inter.y = g_player.pos.y + ((inter.x - g_player.pos.x) * tan(g_ray[i].angle));
    g_vert.next.x = inter.x;
    g_vert.next.y = inter.y;
    while ((g_vert.next.x > 0 && g_vert.next.x < g_game.win_w) && (g_vert.next.y > 0 && g_vert.next.y < g_game.win_h))
    {
        if (is_wall_at(g_vert.next))
        {
            g_vert.hit = TRUE;
            g_vert.wall.x = g_vert.next.x;
            g_vert.wall.y = g_vert.next.y;
            break;
        }
        else
        {
            g_vert.next.x += step.x;
            g_vert.next.y += step.y;
        }
    }
}

void ray_fill(int i)
{
    g_horz.dist = g_horz.hit ? distance(g_player.pos.x, g_player.pos.y, g_horz.wall.x, g_horz.wall.y) : MAX_INT;
    g_vert.dist = g_vert.hit ? distance(g_player.pos.x, g_player.pos.y, g_vert.wall.x, g_vert.wall.y) : MAX_INT;
    if (g_vert.dist < g_horz.dist)
    {
        g_ray[i].dist = g_vert.dist;
        g_ray[i].wall_hit.x = g_vert.wall.x;
        g_ray[i].wall_hit.y = g_vert.wall.y;
        g_ray[i].vert_hit = TRUE;
    }
    else
    {
        g_ray[i].dist = g_horz.dist;
        g_ray[i].wall_hit.x =g_horz.wall.x;
        g_ray[i].wall_hit.y = g_horz.wall.y;
        g_ray[i].vert_hit = FALSE;
    }
}

void cast_ray(int i)
{
    g_ray[i].angle = normalize_angle(g_ray[i].angle);
    g_ray[i].ray_d = ((g_ray[i].angle > 0 && g_ray[i].angle < M_PI)? 1 : 0);
    g_ray[i].ray_up = !g_ray[i].ray_d;
    g_ray[i].ray_r = ((g_ray[i].angle < M_PI * 0.5 || g_ray[i].angle > 1.5 * M_PI) ? 1 : 0);
    g_ray[i].ray_l = !g_ray[i].ray_r;

    init_inter(g_horz);
    init_inter(g_vert);
    hor_inter(i);
    ver_inter(i);
    ray_fill(i);
}

void cast_allrays()
{
    int id;
    float ray_angle;

    id = 0; 
    ray_angle= g_player.rot_angle - (FOV / 2);
    while (id < g_game.win_w)
    {
        g_ray[id].angle = ray_angle;
        cast_ray(id);
        ray_angle += FOV / g_game.win_w;
        id++;
    }
}

// void    cast_allrays()
// {
//     int     i;
//     float   ray_angle;

//     i = 0;
//     ray_angle = g_player.rot_angle - (FOV / 2);
//     while (i < g_game.win_w)
//     {
//         g_ray[i].angle = ray_angle;
//         cast_ray(i);
//         ray_angle += FOV / g_game.win_w;
//         i++;
//     }
    
// }

void    render_rays()
{
    int i;
    t_line ray;

    ray.color = 0xFF0000;
    i = 0;
    while (i < g_game.win_w)
    {
        ray.pos.x = MINI_MAP_SCALE * g_player.pos.x;
        ray.pos.y = MINI_MAP_SCALE * g_player.pos.y;
        ray.dist = g_ray[i].dist * MINI_MAP_SCALE;
        ray.alpha = g_ray[i].angle;
        if (ray.pos.x <= g_game.win_w && ray.pos.y <= g_game.win_h)
            line(ray);
        i++;
    }
}

// void cast_horz(int id)
// {
//     t_pos step;
//     t_pos inter;
    
//     step.y = TILE_SIZE;
//     step.y *= (g_ray[id].ray_d ? 1 : -1);
//     step.x = step.y / tan(g_ray[id].angle);
//     inter.y = floor(g_player.pos.y / TILE_SIZE) * TILE_SIZE;
//     inter.y += (g_ray[id].ray_d ? TILE_SIZE : 0);
//     inter.y += (g_ray[id].ray_up ? -1 : 0);
//     inter.x = g_player.pos.x + ((inter.y - g_player.pos.y) / tan(g_ray[id].angle));
    
//     g_horz.next.x = inter.x;
//     g_horz.next.y = inter.y;
//     while ((g_horz.next.x > 0 && g_horz.next.x < g_game.win_w) && (g_horz.next.y > 0 && g_horz.next.y < g_game.win_h))
//     {
//         if (is_wall_at(g_horz.next))
//         {
//             g_horz.hit = TRUE;
//             g_horz.wall.x = g_horz.next.x;
//             g_horz.wall.y = g_horz.next.y;
//             break;
//         }
//         else
//         {
//             g_horz.next.x += step.x;
//             g_horz.next.y += step.y;
//         }
//     }
// }

// void cast_vert(int id)
// {
//     t_pos step;
//     t_pos inter;
    
//     step.x = TILE_SIZE;
//     step.x *= (g_ray[id].ray_l ? -1 : 1);
//     step.y = step.x * tan(g_ray[id].angle);
//     inter.x = floor(g_player.pos.x / TILE_SIZE) * TILE_SIZE;
//     inter.x += (g_ray[id].ray_r ? TILE_SIZE : 0);
//     inter.x += (g_ray[id].ray_l ? -1 : 0);
//     inter.y = g_player.pos.y + ((inter.x - g_player.pos.x) * tan(g_ray[id].angle));
//     g_vert.next.x = inter.x;
//     g_vert.next.y = inter.y;
//     while ((g_vert.next.x > 0 && g_vert.next.x < g_game.win_w) && (g_vert.next.y > 0 && g_vert.next.y < g_game.win_h))
//     {
//         if (is_wall_at(g_vert.next))
//         {
//             g_vert.hit = TRUE;
//             g_vert.wall.x = g_vert.next.x;
//             g_vert.wall.y = g_vert.next.y;
//             break;
//         }
//         else
//         {
//             g_vert.next.x += step.x;
//             g_vert.next.y += step.y;
//         }
//     }
// }

// void cast_ray(int id)
// {
//     g_ray[id].angle = normalize_angle(g_ray[id].angle);
//     g_ray[id].ray_d = ((g_ray[id].angle > 0 && g_ray[id].angle < M_PI)? 1 : 0);
//     g_ray[id].ray_up = !g_ray[id].ray_d;
//     g_ray[id].ray_r = ((g_ray[id].angle < M_PI * 0.5 || g_ray[id].angle > 1.5 * M_PI) ? 1 : 0);    
//     g_ray[id].ray_l = !g_ray[id].ray_r;
//     // init_inter(g_horz);
//     // init_inter(g_vert);
//     cast_horz(id);
//     cast_vert(id);
//     g_horz.dist = g_horz.hit ? distance(g_player.pos.x, g_player.pos.y, g_horz.wall.x, g_horz.wall.y) : MAX_INT;
//     g_vert.dist = g_vert.hit ? distance(g_player.pos.x, g_player.pos.y, g_vert.wall.x, g_vert.wall.y) : MAX_INT;
//     if (g_vert.dist < g_horz.dist)
//     {
//         g_ray[id].dist = g_vert.dist;
//         g_ray[id].wall_hit.x = g_vert.wall.x;
//         g_ray[id].wall_hit.y = g_vert.wall.y;
//         g_ray[id].vert_hit = TRUE;
//     }
//     else
//     {
//         g_ray[id].dist = g_horz.dist;
//         g_ray[id].wall_hit.x = g_horz.wall.x;
//         g_ray[id].wall_hit.y = g_horz.wall.y;
//         g_ray[id].vert_hit = FALSE;
//     }
// }