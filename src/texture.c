#include "../include/cub3d.h"

void load_texture(t_tex *tex)
{
    tex->tex.img = mlx_xpm_file_to_image(g_game.m_ptr, tex->path, &tex->w, &tex->h);
    tex->tex.addr = mlx_get_data_addr(tex->tex.img, &tex->tex.bpp, &tex->tex.length, &tex->tex.e);
}

int  get_text_color(t_tex tex, int x, int y)
{
    if (x >= 0 && x < tex.w && y >= 0 && y < tex.h)
    {
        return(*((unsigned int*)tex.tex.addr + (y * tex.w + x)));
    }
    return 0;
}

void set_text()  
{
    int i = 0;
    
    while (i < 4)
    {
        g_tex[i].w = 64;
        g_tex[i].h = 64;
        i++;
    }
    
    load_texture(&g_tex[N_NO]);
    load_texture(&g_tex[N_SO]);
    load_texture(&g_tex[N_WE]);
    load_texture(&g_tex[N_EA]);
}

t_pos    set_pos(t_pos *pos, float x, float y)
{
    pos->x = x;
    pos->y = y;
    return *pos;
}

int texture(int i)
{
    t_pos pos;


    if(!is_wall_at(set_pos(&pos, g_ray[i].wall_hit.x, g_ray[i].wall_hit.y - 1)))
        return N_NO;
    else if (!is_wall_at(set_pos(&pos, g_ray[i].wall_hit.x, g_ray[i].wall_hit.y + 1)))
        return N_SO;
    if (!is_wall_at(set_pos(&pos, g_ray[i].wall_hit.x - 1, g_ray[i].wall_hit.y)))
        return N_WE;
    else if (!is_wall_at(set_pos(&pos, g_ray[i].wall_hit.x + 1, g_ray[i].wall_hit.y)))
        return N_EA;
    return 0;
}