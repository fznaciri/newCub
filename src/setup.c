#include "../include/cub3d.h"

void    initialize_window(void)
{
    g_game.m_ptr = mlx_init();
    if (!g_game.m_ptr)
        write_exit("ERROR\nINITIALIZING THE SERVER.\n");
    g_game.w_ptr = mlx_new_window(g_game.m_ptr, g_game.win_w, g_game.win_h, "Cub3D");
    if (!g_game.w_ptr)
        write_exit("ERROR\nCREATING THE WINDOW.\n");
    g_img.img = mlx_new_image(g_game.m_ptr,  g_game.win_w, g_game.win_h);
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp, &g_img.length, &g_img.e);
}

int destroy_window(void)
{
    mlx_clear_window(g_game.m_ptr, g_game.w_ptr);
    mlx_destroy_window(g_game.m_ptr, g_game.w_ptr);
    exit(0);
    return 0;
}

void process_input(void)
{
    mlx_hook(g_game.w_ptr, EVENT_KEYDOWN, 0, key_down, (void*)0);
    mlx_hook(g_game.w_ptr, EVENT_KEYUP, 0, key_up, (void*)0);
    mlx_hook(g_game.w_ptr, EVENT_EXIT, 0, destroy_window, (void*)0);
}

void setup(void)
{
    g_player.turn_dir = 0;
    g_player.walk_dir = 0;
    if(!(g_ray = malloc(sizeof(t_ray) * g_game.win_w)))
        write_exit("error\nrays allocation fails");
    initialize_window();  
    process_input();
    set_text();
    sp_pos();
}

void update()
{
    move_player();
    cast_allrays();
    update_sp_d();
}

void render(void)
{
    render_3dwall();
    // render_map();
    // render_rays();
    // render_player();
    sprites();
}

void clear_image(void)
{   
    t_rec rec;

    rec.pos.x = 0;
    rec.pos.y = 0;
    rec.size.x = g_game.win_w;
    rec.size.y = g_game.win_h;
    rec.color = 0x000000;
    rect(rec);
}

int main_loop()
{
    clear_image();
    update(); 
    render();
    mlx_put_image_to_window(g_game.m_ptr, g_game.w_ptr, g_img.img, 0, 0);
    return 0;
}