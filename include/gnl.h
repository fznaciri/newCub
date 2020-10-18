#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define BUFFER_SIZE 32

int		gnl(int fd, char **line);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strdup(const char *s1);

#endif