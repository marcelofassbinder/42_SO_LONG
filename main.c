/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:08:16 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/19 16:44:23 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_game *game)
{
	if (key == ESC)
		close_game(game, 0);
	else if (key == UP || key == KEY_W)
	{
		game->player_current = game->player_up;
		change_player_position(game, game->map.player_position.y - 1, game->map.player_position.x);
	}
	else if (key == DOWN || key == KEY_S)
	{
		game->player_current = game->player_down;
		change_player_position(game, game->map.player_position.y + 1, game->map.player_position.x);
	}
	else if(key == LEFT || key == KEY_A)
	{
		game->player_current = game->player_left;
		change_player_position(game, game->map.player_position.y, game->map.player_position.x - 1);
	}
	else if (key == RIGHT || key == KEY_D)
	{
		game->player_current = game->player_right;
		change_player_position(game, game->map.player_position.y, game->map.player_position.x + 1);
	}
	return(ft_printf(1, "The key %i has been pressed.\n", key));
}

void	change_player_position(t_game *game, int new_y, int new_x)
{
	int	last_x;
	int	last_y;

	last_y = game->map.player_position.y;
	last_x = game->map.player_position.x;

	if (game->map.map_array[new_y][new_x] != WALL)
	{
		if (game->map.map_array[new_y][new_x] == COLLECTIBLE)
			game->map.coins--;
		if (game->map.map_array[new_y][new_x] == EXIT)
		{
			game->map.map_array[new_y][new_x] = EXIT;
			game->map.map_array[last_y][last_x] = EMPTY;
			if (game->map.coins == 0)
				close_game(game, 1);
		}
		else if (game->map.map_array[last_y][last_x] == EXIT)
		{
			game->map.map_array[last_y][last_x] = EXIT;
			game->map.map_array[new_y][new_x] = PLAYER;
			game->exit = game->exit;
		}
		else
		{
			game->map.map_array[last_y][last_x] = EMPTY;
			game->map.map_array[new_y][new_x] = PLAYER;
		}
		game->map.player_position.y = new_y;
		game->map.player_position.x = new_x;
		game->count_moves++;
		render_map(game);
	}
}

int	close_window(t_game *game)
{
	close_game(game, 0);
	return(0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	*game;
	int		fd;

	if(check_input(argc, argv) != 1)
		exit(2);
	fd = open(argv[1], O_RDONLY);
	map = init_map(fd);
	if(check_map(map) == 1)
	{	
		print_map(map);
		game = init_game(map);
		render_map(game);
		mlx_key_hook(game->mlx_win, handle_input, game);
		mlx_hook(game->mlx_win, 17, (1L << 2), close_window, game);
		mlx_loop(game->mlx_ptr);
	}
}	
