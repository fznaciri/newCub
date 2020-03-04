#include "../cub3d.h"
 int     map[16][30] = {
        {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 1},
        {1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 1},
        {1 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,0 ,0 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,0 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,1 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,0 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,0 ,1 ,1 ,1 ,1 ,1 ,0 ,1 ,1 ,1 ,1 ,0 ,0 ,0 ,0, 1},
        {1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1, 1}
    };
void    render_map(t_game *game)
{
    float x, y;
    t_rec rec;

    rec.size.y = TILE_SIZE * SCALE; //(int)floor(game->setting.r.y / 14);
    rec.size.x = TILE_SIZE * SCALE; //(int)floor(game->setting.r.x / 29);
    y = 0;
    while (y < 30)
    {
        x = 0;
        while (x < 16)
        {
            if(map[(int)x][(int)y] == 0)
                rec.color = 16777215;
            else if (map[(int)x][(int)y] == 1)
                rec.color = 0;
            rec.pos.x = y * TILE_SIZE * SCALE;//(int)floor(game->setting.r.x / 29); //* SCALE;
            rec.pos.y = x * TILE_SIZE * SCALE;//(int)floor(game->setting.r.y / 14); //* SCALE;
            draw_rect(game, rec);
            x++;
        }
        y++;
    }
}

int     hit_wall(t_game *game, t_pos pos)
{
    float   index_x;
    float   index_y;
    
    if (pos.x < 0 || pos.x > game->setting.r.x || pos.y < 0 || pos.y > game->setting.r.y)
        return 1;
    index_x = floor(pos.x / TILE_SIZE);//floor(game->setting.r.x / 29));
    index_y = floor(pos.y / TILE_SIZE);//floor(game->setting.r.y / 14));
    return (map[(int)index_y][(int)index_x] == 1 ? 1 : 0);
    if (map[(int)floor(pos.x/ 30)][(int)floor(pos.y/ 16)] == 1)
        return 1;
    return 0;
}

void    wall(t_game *game)
{
    float distance;
    float wall_strip_height;
    float top, j;
    float correct_distance;
    int i, t;
    COLOR color;

    i = 0;
    while (i < game->setting.r.x)
    {
        t = get_texture(game, i);
        distance = (game->setting.r.x / 2) / tan(FOV / 2);
        correct_distance = game->rays[i].distance * cos(game->rays[i].angle - game->player.rotation_angle);
        wall_strip_height = (TILE_SIZE / correct_distance) * distance;
        top = (game->setting.r.y / 2) - (wall_strip_height / 2);
        game->text[t].offset_x = game->rays[i].vertical_hit ? (int)game->rays[i].wall_hity % TILE_SIZE : (int)game->rays[i].wall_hitx % TILE_SIZE;

        j = 0;
        while (j < game->setting.r.y)
        {
            
            if (j < top)
                color = game->celling;
            else if (j < top + wall_strip_height)
            {
                  game->text[t].offset_y =  (j + ((wall_strip_height / 2) - (game->setting.r.y / 2))) * ((float)(game->text[t].height) / (float)wall_strip_height);
                  game->text[t].offset_y = game->text[t].offset_y >= game->setting.r.y ? game->setting.r.y - 1 : game->text[t].offset_y;
                  color = get_text_color(game->text[t], game->text[t].offset_x, game->text[t].offset_y);
            }
            else if (j > top + wall_strip_height)
                color = game->floor;
            my_mlx_pixel_put(&game->data, i, j, color);
            j++;
        }
        i++;
    }
}