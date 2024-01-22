/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:21:42 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/22 17:31:38 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(int fd)
{
	t_map	map;
	map.map_array = read_map(fd);
	map.line = count_lines(map.map_array);
	map.column = ft_strlen(map.map_array[0]);
	map.players = count_appearance(map, PLAYER);
	map.coins = count_appearance(map, COLLECTIBLE);
	map.exit = count_appearance(map, EXIT);
	player_position(map);
	return(map);
}

t_game	init_game(t_map map)
{	
	t_game	game;

	game.map = map;
	game.mlx_ptr = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_ptr, (map.column * SIZE), (map.line * SIZE), "so_long");
	game.player_right = new_sprite(game, "textures/player.xpm");
	game.player_left = new_sprite(game, "textures/player.xpm");
	game.player_up = new_sprite(game, "textures/player.xpm");
	game.player_down = new_sprite(game, "textures/player.xpm");
	game.wall = new_sprite(game, "textures/parede.xpm");
	game.floor = new_sprite(game, "textures/floor.xpm");
	game.exit = new_sprite(game, "textures/exit.xpm");
	game.collectible = new_sprite(game, "textures/cheese.xpm");
	//define_image_positions(game);
	return(game);
}

t_image	new_sprite(t_game game, char *path_to_xpm)
{
	t_image	new_sprite;

	new_sprite.xpm = mlx_xpm_file_to_image(game.mlx_ptr, path_to_xpm, &new_sprite.x, &new_sprite.y);
	if (!new_sprite.xpm)
		error_message("Couldn't find a image.\n", game.map);
	return(new_sprite);	
}