/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:55:02 by marcelo           #+#    #+#             */
/*   Updated: 2024/03/28 15:32:19 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

// * * * LIBRARIES * * *
# include "../mlx_linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>

// * * * MAP DEFINES * * *
# define EMPTY '0'
# define WALL '1'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define JELLY 'J'
# define SIZE 32

// * * * KEY DEFINES * * *
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

// * * * POSITION STRUCT * * *
typedef struct s_position
{
	int	x;
	int	y;
}		t_position;

// * * * IMAGE STRUCT * * *
typedef struct s_image
{
	void		*xpm;
	int			x;
	int			y;
}				t_image;

// * * * MAP STRUCT * * *
typedef struct s_map
{
	char			**map_array;
	int				line;
	int				column;
	int				players;
	int				coins;
	int				exit;
	int				jellyfish;
	t_position		player;
}					t_map;

// * * * GAME STRUCT * * *
typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_map		map;
	t_image		wall;
	t_image		floor;
	t_image		collectible;
	t_image		exit;
	t_image		exit_closed;
	t_image		jellyfish;
	t_image		player_current;
	t_image		player_up;
	t_image		player_down;
	t_image		player_right;
	t_image		player_left;
	int			count_moves;
}				t_game;

// * * * CHECK_ARGS_B.C * * *
int				check_args(int argc, char **argv);
int				check_extension(char *str);

// * * * CHECK_MAP_B.C * * *
int				check_map(t_map map);
int				invalid_char(t_map map);
int				count_appearance(t_map map, char c);
int				surrounded_by_walls(t_map map);

// * * * FREE_FUNCTIONS_B.C * * *
void			free_map(char **map);
void			free_game(t_game *game);
void			close_game(t_game *game, int flag);
int				error_message(char *str, t_map map);

// * * * INIT_STRUCTS_B.C * * *
t_map			init_map(int fd);
t_game			*init_game(t_map map);
t_image			new_sprite(t_game *game, char *path_to_xpm);
t_position		player_position(t_map map);

// * * * MAIN_B.C * * *
void			change_player_pos(t_game *game, int y, int x);
int				handle_input(int key, t_game *game);
int				close_window(t_game *game);

// * * * MAP_B.C * * *
char			**read_map(int fd);
int				count_lines(char **map);
int				check_for_empty_line(char *map_str);
int				has_valid_path(t_map map);
int				valid_path(t_map map, int y, int x, char **copy);

// * * * MOVE_JELLY_B.C * * *
void			move_jelly(t_game *game);
void			change_jelly_pos(t_game *game, int y, int x, int dir);

// * * * RENDER_B.C * * *
void			render_map(t_game *game);
void			identify_sprite(t_game *game, int y, int x);
void			render_sprite(t_game *game, \
t_image sprite, int line, int column);
void			print_movements(t_game *game);

#endif