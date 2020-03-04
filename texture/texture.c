#include "../cub3d.h"

void load_texture(t_game *game) // add path as parameter
{
    int i;

    i = 0;
    while (i < 4)
    {
        game->text[i].img.img = mlx_xpm_file_to_image(game->setting.m_ptr, game->text[i].path, &game->text[i].width, &game->text[i].height);
        game->text[i].img.addr = mlx_get_data_addr(game->text[i].img.img, &game->text[i].img.bits_per_pixel, &game->text[i].img.line_length, &game->text[i].img.endian);
        i++;
    }
}

int  get_text_color(t_text text, int x, int y)
{
    if (x >= 0 && x < text.width && y >= 0 && y < text.height)
    {
        return(*((COLOR*)text.img.addr + (y * text.width + x )));
    }
    return 0;
}
void    set_text(t_game *game)
{
    int i;

    i = 0;
    game->text[T_N].path = strdup("7.xpm");//texture[T_N];
    game->text[T_S].path = strdup("23.xpm");//texture[T_S];
    game->text[T_W].path = strdup("nazi.xpm");//texture[T_W];
    game->text[T_E].path = strdup("eagle.xpm");//texture[T_E];
    while (i < 4)
    {
        game->text[i].width = 64;
        game->text[i].height = 64;
        i++;
    }
}

int     get_texture(t_game *game, int i)
{
    t_pos pos;
    if (!hit_wall(game, set_pos(&pos, game->rays[i].wall_hitx + 1, game->rays[i].wall_hity)))
        return T_W;
    else if (!hit_wall(game, set_pos(&pos, game->rays[i].wall_hitx - 1, game->rays[i].wall_hity)))
        return T_E;
    else if (!hit_wall(game, set_pos(&pos, game->rays[i].wall_hitx, game->rays[i].wall_hity + 1)))
        return T_S;
    else if (!hit_wall(game, set_pos(&pos, game->rays[i].wall_hitx, game->rays[i].wall_hity - 1)))
        return T_N;
    
    return 0;
}