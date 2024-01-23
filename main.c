/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:08:16 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/23 17:20:45 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_game game)
{
	if (key == XK_Escape)
	{
		ft_printf(1, "The key %i (ESC) has been pressed.\n", key);
		free_game(game);
		exit(1);
	}
	change_player_position(key, game);
	return(ft_printf(1, "The key %i has been pressed.\n", key));
}

void	change_player_position(int key, t_game game)
{
	if (key == UP)
	{
		game.map.player_position->y++;
		game.player_current = game.player_up;
	}
	//render_map(game);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;
	int		fd;

	(void)game;
	if(check_input(argc, argv) != 1)
		exit(2);
	fd = open(argv[1], O_RDONLY);
	map = init_map(fd);
	if(check_map(map) == 1)
	{	
		print_map(map);
		game = init_game(map);
		render_map(game);
		mlx_key_hook(game.mlx_win, handle_input, &game);
		mlx_loop(game.mlx_ptr);
	}

}	
