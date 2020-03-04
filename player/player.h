#ifndef PLAYER_H
#define PLAYER_H
#include "../setting/setting.h"

typedef struct s_player 
{
    t_pos pos;
    t_pos size;
    float rotation_angle;
    float move_speed;
    float angle_speed;
    int turn_direction;
    int walk_direction;
}   t_player;

#endif