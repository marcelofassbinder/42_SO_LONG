/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:58:31 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/20 16:24:28 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx_linux/mlx.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>

# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'

typedef struct s_map
{
	int 	line;
	int 	column;
	char			**map_array;
}					t_map;

int				check_input(int argc, char **argv);
int				check_extension(char *str);
char			**read_map(int fd);
void			print_map(t_map map);
int				count_lines(char **map);
int				count_columns(char **map);
t_map			init_map(int fd);
int				check_map(t_map map);
int				count_appearance(t_map map, char c);
int 			invalid_char(t_map map);
int				surrounded_by_walls(t_map map);

#endif