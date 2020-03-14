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
    void        *m_ptr;
    void        *w_ptr;
    char        *title;
    t_pos       res;
    t_player    player;
    t_ray       *rays;
    t_data      data;
    t_text      *text;
    COLOR       celling;
    COLOR       floor;
    t_map       map;
}  t_game;





#endif