#ifndef UTILS_H
# define UTILS_H
#include <string.h>
#include <stdlib.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t  ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void    *ft_realalloc(void *target, int csize, int nsize);
#endif