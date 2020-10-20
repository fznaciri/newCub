#include "../include/cub3d.h"

int key_down(int key)
{
    if (key == 53)
        destroy_window();
    if (key == 123 || key == 0) // left
         g_player.turn_dir = -1;
    if (key == 124 || key == 2) // right
         g_player.turn_dir = 1;
    if (key == 13 || key == 126) // up w 
         g_player.walk_dir = 1;
    if (key == 1 || key == 125) // down s
         g_player.walk_dir = -1;
    return 0;
}

int key_up(int key)
{
    if (key == 123 || key == 124 || key == 0 || key == 2) // turn
         g_player.turn_dir = 0;
    if (key == 13 || key == 1 || key == 126 || key == 125) // up w
         g_player.walk_dir = 0;  
    return 0;
}