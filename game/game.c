#include "../cub3d.h"

int exit_game(t_game *game)
{
	mlx_clear_window(game->setting.m_ptr, game->setting.w_ptr);
    mlx_destroy_window(game->setting.m_ptr, game->setting.w_ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void    render(t_game *game)
{
    wall(game);
    render_map(game);
    render_rays(game);
    render_player(game);
}

void    update(t_game *game)
{
    cast_all_rays(game);
    move_player(game);
}

void    setup(t_game *game)
{
    //char **texture;
    game->text = malloc(sizeof(t_text) * 4);

    // texture = NULL;
    // texture[T_N] = "7.xpm";
    // texture[T_S] = "23.xpm";
    // texture[T_W] = "nazi.xpm";
    // texture[T_E] = "eagle.xpm";
    
    set_text(game);
    load_texture(game);
    game->rays = malloc(sizeof(t_ray) * game->setting.r.x);
    
    game->player.pos.x = floor(game->setting.r.x / 29) * 27;//game->setting.r.x / 2;
    game->player.pos.y = floor(game->setting.r.y / 14) * 6;//game->setting.r.y / 2;
    game->player.size.x = 4;
    game->player.rotation_angle = M_PI / 2;
    game->player.angle_speed = 5 * (M_PI / 180);
    game->player.move_speed = 10;

    game->player.turn_direction = 0;
    game->player.walk_direction = 0;
}
 
void    clear_image(t_game *game)
{
    t_rec r;

    r.pos.x = 0;
    r.pos.y = 0;
    r.size.x = game->setting.r.x;
    r.size.y = game->setting.r.y;
    r.color = 0x00FFFFFF;
    draw_rect(game, r);
}

int    main_loop(t_game *game)
{
    update(game);
    render(game);
    mlx_put_image_to_window(game->setting.m_ptr, game->setting.w_ptr, game->data.img, 0, 0);
    clear_image(game);
    
    return 0;
}