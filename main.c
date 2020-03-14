#include "cub3d.h"



int     main(int ac, char **av)
{  
    t_game game;
    int error;
    int i;
    error = 0;
    if (ac > 0)
     error = load(&game, av[1]);
    printf("%d\n", error);

    game.m_ptr = mlx_init();
    game.title = "Cub3d";
    printf("x : %f\ny : %f\n", game.res.x, game.res.y);
    printf("floor : %d\ncelling : %d\n", game.floor, game.celling);
    printf("texture north :%s\n", game.text[T_N].path);
    printf("texture south :%s\n", game.text[T_S].path);
    printf("texture west :%s\n", game.text[T_W].path);
    printf("texture east :%s\n", game.text[T_E].path);
    printf("sprite :%s\n", game.text[S].path);
    i = 0;
    while (i <game.map.row)
    {
        printf("%s\n", game.map.map[i]);
        i++;
    }
    game.w_ptr = mlx_new_window(game.m_ptr, game.res.x, game.res.y, game.title);
    game.data.img = mlx_new_image(game.m_ptr, game.res.x,  game.res.y);
    game.data.addr = mlx_get_data_addr(game.data.img, &game.data.bits_per_pixel, &game.data.line_length, &game.data.endian);
    
    setup(&game);
    mlx_hook(game.w_ptr, EVENT_KEYDOWN, 0, key_down, &game);
    mlx_hook(game.w_ptr, EVENT_KEYUP, 0, key_up, &game);
    mlx_hook(game.w_ptr, EVENT_EXIT, 0, exit_game, &game);
    
    mlx_loop_hook(game.m_ptr, &main_loop, &game);
    
    
    mlx_loop(game.m_ptr);
    return (0);
}