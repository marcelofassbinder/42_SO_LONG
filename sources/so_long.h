/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:58:31 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/26 12:58:14 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx_linux/mlx.h"
#include "../ft_printf/ft_printf.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>


// --- MAP DEFINES --- 
# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define SIZE 32

// --- KEY DEFINES ---
# define UP XK_Up
# define DOWN XK_Down
# define LEFT XK_Left
# define RIGHT XK_Right
# define KEY_W XK_w
# define KEY_S XK_s
# define KEY_A XK_a
# define KEY_D XK_d
# define ESC XK_Escape
# define END XK_End

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
	t_position		player;
}					t_map;

typedef struct s_image
{
	void		*xpm;
	int			x;
	int			y;
}				t_image;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_map		map;
	t_image 	wall;
	t_image 	floor;
	t_image 	collectible;
	t_image 	exit;
	t_image 	exit_closed;
	t_image 	player_current;
	t_image 	player_up;
	t_image 	player_down;
	t_image		player_right;
	t_image		player_left;
	int 		count_moves;
}				t_game;

// --- VALIDATION FUNCTIONS ---

int				check_args(int argc, char **argv);
int				check_extension(char *str);
int				check_map(t_map map);
int				count_lines(char **map);
int				surrounded_by_walls(t_map map);
int				check_for_empty_line(char *map_str);
int 			invalid_char(t_map map);
int				has_valid_path(t_map map);
int 			valid_path(t_map map, int y, int x, char **copy);
char			**read_map(int fd);
void			print_map(t_map map);
int				count_appearance(t_map map, char c);
t_map			init_map(int fd);
int				error_message(char *str, t_map map);
t_game			*init_game(t_map map);
t_image			new_sprite(t_game *game, char *path_to_xpm);
void			render_map(t_game *game);
void			identify_sprite(t_game *game, int y, int x);
void			render_sprite(t_game *game, t_image sprite, int line, int column);
t_position		player_position(t_map map);
void			free_map(char **map);
void			free_game(t_game *game);
void			change_player_pos(t_game *game, int y, int x);
void			close_game(t_game *game, int victory);
void			print_movements(t_game *game);
int				handle_input(int key, t_game *game);
int				close_window(t_game *game);

#endif