/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:49:38 by marcelo           #+#    #+#             */
/*   Updated: 2024/03/26 19:48:49 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	else if(key == LEFT || key == KEY_A)
	{
		game->player_current = game->player_left;
		change_player_pos(game, game->map.player.y, game->map.player.x - 1);
	}
	else if (key == RIGHT || key == KEY_D)
	{
		game->player_current = game->player_right;
		change_player_pos(game, game->map.player.y, game->map.player.x + 1);
	}
	move_jelly(game);
	render_map(game);
	return(ft_printf(1, "The key %i has been pressed.\n", key));
}

void	change_player_pos(t_game *game, int new_y, int new_x)
{
	if (game->map.map_array[new_y][new_x] != WALL)
	{
		if (game->map.map_array[new_y][new_x] == JELLYFISH)
			close_game(game, 2);
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
	}
}

int	close_window(t_game *game)
{
	close_game(game, 0);
	return(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	*game;
	int		fd;

	if(check_args(argc, argv) != 1)
		return(EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	map = init_map(fd);
	if(check_map(map) == 1)
	{
		game = init_game(map);
		render_map(game);
		mlx_key_hook(game->mlx_win, handle_input, game);
		mlx_hook(game->mlx_win, 17, (1L << 2), close_window, game);
		mlx_loop(game->mlx_ptr);
	}
}	
