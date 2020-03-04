#include "../cub3d.h"

t_pos    set_pos(t_pos *pos, float x, float y)
{
    pos->x = x;
    pos->y = y;
    return *pos;
}

t_pos    copy_pos(t_pos *pos, t_pos s)
{
    pos->x = s.x;
    pos->y = s.y;
    return *pos;
}
