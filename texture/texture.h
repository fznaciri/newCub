#ifndef TEXTURE_H
# define TEXTURE_H
#define COLOR   int
# define T_N 0
# define T_S 1
# define T_W 2
# define T_E 3
# define S 4
// typedef struct  s_texture
// {
//     COLOR   **north;
//     COLOR   **east;
//     COLOR   **souht;
//     COLOR   **west;
// }  t_texture;
typedef struct  s_text {
    t_data  img;
    char    *path;
    int     width;
    int     height;
    float   offset_x;
    float   offset_y;
}   t_text;

#endif