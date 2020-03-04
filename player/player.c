#include "../cub3d.h"

void    render_player(t_game *game)
{
    t_cercle c;
    t_line l;

    l.d = 40 * SCALE;
    copy_pos(&l.pos, game->player.pos);
    l.alpha = game->player.rotation_angle;
    l.pos.x *= SCALE;
    l.pos.y *= SCALE;
    l.color = 0x0000FF00;
    c.color = 0x0000FF00;
    c.pos.x = game->player.pos.x * SCALE;
    c.pos.y = game->player.pos.y * SCALE;
    c.r = game->player.size.x * SCALE;

    draw_cercle(game, c);
    draw_line(game, l);
}

void    move_player(t_game *game)
{
    t_pos pos;
    float step;

    step = game->player.walk_direction * game->player.move_speed;
    game->player.rotation_angle += game->player.turn_direction * game->player.angle_speed;
    pos.x = game->player.pos.x + cos(game->player.rotation_angle) * step;
    pos.y = game->player.pos.y + sin(game->player.rotation_angle) * step;

    if (!hit_wall(game, pos))
        set_pos(&(game->player.pos), game->player.pos.x + cos(game->player.rotation_angle) * step, game->player.pos.y + sin(game->player.rotation_angle) * step);
}
