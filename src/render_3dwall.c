#include "../include/cub3d.h"

void render_3dwall()
{
    int i = 0;
    int wall_height;
    float correct_distance;
    int color;
    int distance_from_top;
    int j;
    int wall_top;
    int wall_bot;
    int t;
    
    set_text();
    while(i < g_game.win_w)
    {
        correct_distance = g_ray[i].dist * cos(g_ray[i].angle - g_player.rot_angle);
        wall_height = (TILE_SIZE / correct_distance) * ((g_game.win_w / 2) / (tan(FOV / 2)));
        wall_top = ((g_game.win_h / 2) - (wall_height / 2));
        wall_top = wall_top < 0 ? 0 : wall_top;
        wall_bot = ((g_game.win_h / 2) + (wall_height / 2));
        wall_bot = wall_bot > g_game.win_h ? g_game.win_h : wall_bot; 
       j = 0;
       t = texture(i);
       if (g_ray[i].vert_hit)
           g_tex[t].pos.x = (int)g_ray[i].wall_hit.y % TILE_SIZE;
       else
           g_tex[t].pos.x = (int)g_ray[i].wall_hit.x % TILE_SIZE;
        g_tex[t].pos.x = g_tex[t].pos.x < 0 ? 0 : g_tex[t].pos.x;
       
        while(j < g_game.win_h)
       {
            if (j < wall_top) // ceiling
                color = g_game.ceeling;
            else if (j < wall_bot) // wall 
            {
                distance_from_top = j + (wall_height / 2) - (g_game.win_h / 2);
                
                g_tex[t].pos.y = distance_from_top * ((float)g_tex[t].h / wall_height);
                g_tex[t].pos.y = g_tex[t].pos.y >= g_game.win_h ? g_game.win_h - 1 : g_tex[t].pos.y;
                color = get_text_color(g_tex[t], g_tex[t].pos.x, g_tex[t].pos.y);
            } 
            else if (j < g_game.win_h) // floor
                color = g_game.floor;
           my_mlx_pixel_put(i, j, color);
           j++;
       }
       i++;
    }
}