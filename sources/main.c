/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:08:16 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/28 18:36:23 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Perform an action, based on the key that is pressed, and renders the map*/
/*Returns the message indicating which key was pressed*/
int	handle_input(int key, t_game *game)
{
	if (key == ESC)
		close_game(game, 0);
	else if (key == UP || key == KEY_W)
	{
		game->player_current = game->player_up;
		change_player_pos(game, game->map.player.y - 1, game->map.player.x);
	}
	else if (key == DOWN || key == KEY_S)
	{
		game->player_current = game->player_down;
		change_player_pos(game, game->map.player.y + 1, game->map.player.x);
	}
	else if (key == LEFT || key == KEY_A)
	{
		game->player_current = game->player_left;
		change_player_pos(game, game->map.player.y, game->map.player.x - 1);
	}
	else if (key == RIGHT || key == KEY_D)
	{
		game->player_current = game->player_right;
		change_player_pos(game, game->map.player.y, game->map.player.x + 1);
	}
	return (ft_printf(1, "The key %i has been pressed.\n", key));
}

/*Changes the player position and increases the moves counter,
 based on its new coordinates(x, y). 
If the next position is a wall, does nothing.
If the next position is a collectible, decrease the quantity of coins. 
in the map struct.
If the next position is the exit, and there are no coins, ends the game, 
indicating victory.
If the actual position is the exit, it means that there uncollected coins, 
and the game is not over, so the next position must be the player
If the actual position is empty, the next must be the player.*/
void	change_player_pos(t_game *game, int new_y, int new_x)
{
	if (game->map.map_array[new_y][new_x] != WALL)
	{
		if (game->map.map_array[new_y][new_x] == COLLECTIBLE)
			game->map.coins--;
		if (game->map.map_array[new_y][new_x] == EXIT)
		{
			game->map.map_array[game->map.player.y][game->map.player.x] = EMPTY;
			if (game->map.coins == 0)
				close_game(game, 1);
		}
		else if (game->map.map_array[game->map.player.y][game->map.player.x]
			== EXIT)
			game->map.map_array[new_y][new_x] = PLAYER;
		else
		{
			game->map.map_array[game->map.player.y][game->map.player.x] = EMPTY;
			game->map.map_array[new_y][new_x] = PLAYER;
		}
		game->map.player.y = new_y;
		game->map.player.x = new_x;
		game->count_moves++;
		render_map(game);
	}
}

/*Calls the function "close_game" with the flag '0', indicating the user 
pressed a key that close the window.*/
/*Returns the macro "EXIT_SUCCESS", the same as 0, 
indicating that no error has occured.*/
int	close_window(t_game *game)
{
	close_game(game, 0);
	return (EXIT_SUCCESS);
}

/*Executes the program.
1) Check the arguments
2) Open the .ber file
3) Initialize the map structure
4) Check if map is valid
5) Initialize the game structure
6) Render all the images together
7) Receives the input and perform an action, based on the pressed key
8) Closes the window if the 'X' is clicked
9) mlx_loop keeps the window active. */
int	main(int argc, char **argv)
{
	t_map	map;
	t_game	*game;
	int		fd;

	if (check_args(argc, argv) != 1)
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	map = init_map(fd);
	if (check_map(map) == 1)
	{
		game = init_game(map);
		render_map(game);
		mlx_key_hook(game->mlx_win, handle_input, game);
		mlx_hook(game->mlx_win, 17, (1L << 2), close_window, game);
		mlx_loop(game->mlx_ptr);
	}
}
