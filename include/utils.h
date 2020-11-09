/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:09:13 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 09:52:08 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "structs.h"
# define BUFFER_SIZE 32

int			gnl(int fd, char **line);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strndup(const char *s1, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			bigger(int a, int b);
void		skip_digit(char **s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s1);
int			spaces(char *s);
void		skip_spaces(char **s);
float		distance(float x1, float y1, float x2, float y2);
float		normalize_angle(float angle);
int			ft_strcmp(const char *s1, const char *s2);
t_pos		set_pos(t_pos *pos, float x, float y);
void		fill_spaces(char *str, int s, int e);
int			is_map(char x);
int			is_p(char x);
int			is_zsp(char x);

#endif
