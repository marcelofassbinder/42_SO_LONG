/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:58:31 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/21 18:32:00 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx_linux/mlx.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>

# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define SIZE 32

typedef struct s_position
{
	int	x;
	int	y;
}		t_position;

typedef struct s_map
{
	char			**map_array;
	int 			line;
	int 			column;
	int				players;
	int				coins;
	int				exit;
	t_position		*player_position;
}					t_map;

typedef struct s_image
{
	void	*xpm;
	int		x;
	int		y;
}			t_image;

typedef struct s_game
{
	t_map		map;
	void		*mlx_ptr;
	void		*mlx_win;
	t_image 	wall;
	t_image 	floor;
	t_image 	collectible;
	t_image 	exit;
	t_image 	player_up;
	t_image 	player_down;
	t_image		player_right;
	t_image		player_left;
	int 		count_moves;
}				t_game;

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
int				check_for_empty_line(char *map_str);
void			player_position(t_map map);
int				error_message(char *str, t_map map);
t_game			init_game(t_map map);
t_image			new_sprite(t_game game, char *path_to_xpm);
void			render_first_image(t_game game);
void			render_sprite(t_game game, int y, int x);

#endif