#include "include/cub3d.h"

int     main(int ac, char **av)
{
    int i = 0, j = 0;

    if (ac <= 1)
        write_exit("Error\nfile .cup argument is missing\n");
    if (ac > 3)
        write_exit("Error\ntoo many argument\n");
    if (ac >= 2)
        load_file(av[1]);
    printf("\n\n\n\nEA |%s|\nWE |%s|\nSO |%s|\nNO |%s|\nS |%s|\nC |%d|\nR |%d| |%d|\nF |%d|\nMAP_H |%d|\nMAP_W |%d|\n\n",
			g_game.tex[N_EA].path, g_game.tex[N_WE].path, g_game.tex[N_SO].path, g_game.tex[N_NO].path, g_game.s_path, g_game.ceeling, g_game.win_w, g_game.win_h, g_game.floor, g_game.map.h, g_game.map.w);

	while (i < g_game.map.h)
	{
		printf("|%s|\n",g_game.map.map[i]);
		i++;
	}
}