#ifndef GAME_H
#define GAME_H
#include "../setting/setting.h"
#include "../player/player.h"
#include "../texture/texture.h"

# define EVENT_KEYDOWN 2
# define EVENT_KEYUP 3
# define EVENT_EXIT 17
# define EXIT_SUCCESS 0


typedef struct  s_game
{
    t_setting   setting;
    t_player    player;
    t_ray       *rays;
    t_data      data;
    t_text      *text;
    COLOR       celling;
    COLOR       floor;
    //char        **map;
}  t_game;





#endif