/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:33:06 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/09 09:53:58 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <errno.h>
# include <fcntl.h>
# include "structs.h"

void		tozero_tkn();
void		treat_element(char *element);
void		load_file(char *path);
int			empty_line(char *line);
void		treat_r(char *s);
void		treat_no(char *s);
void		treat_so(char *s);
void		treat_we(char *s);
void		treat_ea(char *s);
void		treat_s(char *s);
void		treat_f(char *s);
void		treat_c(char *s);
t_color		treat_color(char **s);
void		load_error(char *str);
void		check_before_map();
void		treat_m(char *element);
void		adjust_map();
void		verify_map();
void		verify_border(void);
void		verify_player();
void		get_player();
void		init_angle(int i, int j);
void		check_player(int nop);

#endif
