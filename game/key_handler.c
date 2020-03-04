#include "../cub3d.h"

int key_down(int key, t_game *game)
{
    if (key == ESC_KEY)
      exit_game(game);
    else if (key == KEY_W || key == KEY_UP)
      game->player.walk_direction = 1;
    else if (key == KEY_S || key == KEY_DOWN)
      game->player.walk_direction = -1;
    else if (key == KEY_D || key == KEY_RIGHT)
      game->player.turn_direction = 1;
    else if (key == KEY_A || key == KEY_LEFT)
      game->player.turn_direction = -1;
    return 0;
}

int key_up(int key, t_game *game)
{
    if (key == KEY_S || key == KEY_W || key == KEY_UP || key == KEY_DOWN)
      game->player.walk_direction = 0;
    else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_A || key == KEY_D)
      game->player.turn_direction = 0;
    return 0;
}