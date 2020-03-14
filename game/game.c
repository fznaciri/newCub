#include "../cub3d.h"

int exit_game(t_game *game)
{
	mlx_clear_window(game->m_ptr, game->w_ptr);
    mlx_destroy_window(game->m_ptr, game->w_ptr);
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
    
    move_player(game);
    cast_all_rays(game);
}

void    setup(t_game *game)
{
    set_text(game);
    if (!load_texture(game))
        exit_game(game);
    game->rays = malloc(sizeof(t_ray) * game->res.x);
    
    game->player.pos.x = floor(game->res.x / 29) * 27;
    game->player.pos.y = floor(game->res.y / 14) * 6;
    game->player.size.x = 4;
    game->player.rotation_angle = 3 * M_PI / 2;
    game->player.angle_speed = 8 * (M_PI / 180);
    game->player.move_speed = 10;

    game->player.turn_direction = 0;
    game->player.walk_direction = 0;
}
 
void    clear_image(t_game *game)
{
    t_rec r;

    r.pos.x = 0;
    r.pos.y = 0;
    r.size.x = game->res.x;
    r.size.y = game->res.y;
    r.color = 0x00FFFFFF;
    draw_rect(game, r);
}

int    main_loop(t_game *game)
{
    clear_image(game);
    update(game);
    render(game);
    mlx_put_image_to_window(game->m_ptr, game->w_ptr, game->data.img, 0, 0);
    
    return 0;
}