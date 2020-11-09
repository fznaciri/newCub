#include "include/cub3d.h"

int     main(int ac, char **av)
{
    if (ac <= 1)
        write_exit("Error\nfile .cub argument is missing\n");
    if (ac > 3)
        write_exit("Error\ntoo many argument\n");
    if (ac >= 2)
        load_file(av[1]);
    setup();
    if (ac == 3)
    {
        if (ft_strcmp(av[2], "--save") == 0)
            save();
        else
            write_exit("Error\n");
    }
    mlx_loop_hook(g_game.m_ptr, main_loop, (void*)0);
    mlx_loop(g_game.m_ptr);
    leakcheckfull();
    return 0;
}