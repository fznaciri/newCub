#include "../cub3d.h"


void    cast_all_rays(t_game *game)
{
    int     i;
    float   ray_angle;

    i = 0;
    ray_angle = game->player.rotation_angle - (FOV / 2);
    while (i < game->res.x)
    {
        cast_ray(game, i);
        game->rays[i].angle = ray_angle;
        copy_pos(&(game->rays[i].pos), game->player.pos);
        ray_angle += FOV / game->res.x;
        i++;
    }
}

void    render_rays(t_game *game)
{
    int i;
    t_line ray;

    ray.color = 0xFF0000;
    i = 0;
    while (i < game->res.x)
    {
        copy_pos(&(ray.pos), game->rays[i].pos);
        ray.pos.x *= SCALE;
        ray.pos.y *= SCALE;
        ray.d = game->rays[i].distance * SCALE;
        ray.alpha = game->rays[i].angle;
        if (ray.pos.x <= game->res.x && ray.pos.y <= game->res.y)
            draw_line(game, ray);
        i++;
    }
}

void cast_ray(t_game *game, int id)
{
    float xstep;
    float ystep;
    float xintercept; // coordinate of the first intersection
    float yintercept;
    t_pos next_horz;
    int horz_hit = 0;
    float horz_wall_hitx = 0;
    float horz_wall_hity = 0;
    int horz_wall_content = 0;
    float horz_distance;
    float vert_distance;
    
    game->rays[id].angle = normalize_angle(game->rays[id].angle);
    
    int facing_down = ((game->rays[id].angle > 0 && game->rays[id].angle < M_PI)? 1 : 0);
    int facing_up = !facing_down;
    
    int facing_right = ((game->rays[id].angle < M_PI * 0.5 || game->rays[id].angle > 1.5 * M_PI) ? 1 : 0);    
    int facing_left = !facing_right;
    
    /////////////////////////////
    // horizontal intersection //
    ////////////////////////////
    
    ystep = TILE_SIZE;
    ystep *= (facing_down ? 1 : -1);
    
    xstep = ystep / tan(game->rays[id].angle);
   // xstep *= ((facing_right && xstep < 0) ? -1 : 1);
   // xstep *= ((facing_left && xstep > 0) ? -1 : 1);
    
    
    yintercept = floor(game->player.pos.y / TILE_SIZE) * TILE_SIZE;
    yintercept += (facing_down ? TILE_SIZE : 0);
    yintercept += (facing_up ? -1 : 0); // make it part of the bloc above the line 
    xintercept = game->player.pos.x + ((yintercept - game->player.pos.y) / tan(game->rays[id].angle));
    
    next_horz.x = xintercept;
    next_horz.y = yintercept;
    
    while ((next_horz.x > 0 && next_horz.x < game->res.x) && (next_horz.y > 0 && next_horz.y < game->res.y))
    {
        if (hit_wall(game, next_horz))
        {
            horz_hit = 1;
            horz_wall_hitx = next_horz.x;
            horz_wall_hity = next_horz.y;
            horz_wall_content = 1;//map[(int)floor(next_horzy / TILE_SIZE)][(int)floor(next_horzx / TILE_SIZE)];
            break;
        }
        else
        {
            next_horz.x += xstep;
            next_horz.y += ystep;
        }
    }

    ///////////////////////////////////////////////
    //////////// vertical intersection  ///////////
    ///////////////////////////////////////////////

    t_pos next_vert;
    int vert_hit = 0;
    float vert_wall_hitx = 0;
    float vert_wall_hity = 0;
    int vert_wall_content = 0;
    
    xstep = TILE_SIZE;
    xstep *= (facing_left ? -1 : 1);
    
    ystep = xstep * tan(game->rays[id].angle);
    //ystep *= ((facing_up && ystep > 0) ? -1 : 1);
   // ystep *= ((facing_down && ystep < 0) ? -1 : 1);
    
    
    xintercept = floor(game->player.pos.x / TILE_SIZE) * TILE_SIZE;
    xintercept += (facing_right ? TILE_SIZE : 0);
    xintercept += (facing_left ? -1 : 0);
    yintercept = game->player.pos.y + ((xintercept - game->player.pos.x) * tan(game->rays[id].angle));
    
    next_vert.x = xintercept;
    next_vert.y = yintercept;
    
    while ((next_vert.x > 0 && next_vert.x < game->res.x) && (next_vert.y > 0 && next_vert.y < game->res.y))
    {
        if (hit_wall(game, next_vert))
        {
            vert_hit = 1;
            vert_wall_hitx = next_vert.x;
            vert_wall_hity = next_vert.y;
            vert_wall_content = 1;//map[(int)floor(next_verty / TILE_SIZE)][(int)floor(next_vertx / TILE_SIZE)];
            break;
        }
        else
        {
            next_vert.x += xstep;
            next_vert.y += ystep;
        }
    }
    horz_distance = horz_hit ? distance(game->player.pos.x, game->player.pos.y, horz_wall_hitx, horz_wall_hity) : MAX_INT;
    vert_distance = vert_hit ? distance(game->player.pos.x, game->player.pos.y, vert_wall_hitx, vert_wall_hity) : MAX_INT;
    if (vert_distance < horz_distance)
    {
        game->rays[id].distance = vert_distance;
        game->rays[id].wall_hitx = vert_wall_hitx;
        game->rays[id].wall_hity = vert_wall_hity;
        game->rays[id].wall_hitcontent = vert_wall_content;
        game->rays[id].vertical_hit = 1;
    }
    else
    {
        game->rays[id].distance = horz_distance;
        game->rays[id].wall_hitx = horz_wall_hitx;
        game->rays[id].wall_hity = horz_wall_hity;
        game->rays[id].wall_hitcontent = horz_wall_content;
        game->rays[id].vertical_hit = 0;
    }
    game->rays[id].angle = game->rays[id].angle;
    game->rays[id].facing_down = facing_down;
    game->rays[id].facing_up = facing_up;
    game->rays[id].facing_right = facing_right;
    game->rays[id].facing_left = facing_left;
}

 float normalize_angle(float angle)
{
    angle = remainderf(angle, 2 * M_PI);
    if (angle < 0)
         angle += 2 * M_PI; 
    return (angle);
}

float distance(float x1, float y1, float x2, float y2)
{
    return (hypotf((x2 - x1), (y2 - y1)));
}
