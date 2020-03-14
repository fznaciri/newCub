#include "utils.h"

void    *ft_realalloc(void *target, int csize, int nsize)
{
    void    *ntarget;
    int     size;

    size = 0;
    if(csize == nsize)
        return target;
    if (csize > nsize)
        return NULL;
    if (!(ntarget = malloc(nsize)))
        return NULL;
    while (size < csize)
    {
        ((char*)ntarget)[size] = ((char*)target)[size];
        size++;
    }
    while (size < nsize)
        ((char*)ntarget)[size++] = 0;
    free(target);
    return ntarget;
}