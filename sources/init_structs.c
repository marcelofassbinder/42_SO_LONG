/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:21:42 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/27 14:01:33 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	init_map(int fd)
{
	t_map	map;

	map.map_array = read_map(fd);
	map.line = count_lines(map.map_array);
	map.column = ft_strlen(map.map_array[0]);
	map.players = count_appearance(map, PLAYER);
	map.coins = count_appearance(map, COLLECTIBLE);
	map.exit = count_appearance(map, EXIT);
	return (map);
}

t_game	*init_game(t_map map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->map = map;
	game->map.player = player_position(game->map);
	game->mlx_ptr = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx_ptr, \
	(map.column * SIZE), (map.line * SIZE), "so_long");
	game->player_right = new_sprite(game, "textures/bobfundo.xpm");
	game->player_left = new_sprite(game, "textures/bob_left.xpm");
	game->player_up = new_sprite(game, "textures/bob_up.xpm");
	game->player_down = new_sprite(game, "textures/bob_down.xpm");
	game->player_current = game->player_right;
	game->wall = new_sprite(game, "textures/sand.xpm");
	game->floor = new_sprite(game, "textures/background.xpm");
	game->exit = new_sprite(game, "textures/pineapple.xpm");
	game->exit_closed = new_sprite(game, "textures/bobpineapple.xpm");
	game->collectible = new_sprite(game, "textures/krabby.xpm");
	game->count_moves = 0;
	return (game);
}

t_image	new_sprite(t_game *game, char *path_to_xpm)
{
	t_image	new_sprite;

	new_sprite.xpm = mlx_xpm_file_to_image(game->mlx_ptr, \
	path_to_xpm, &new_sprite.x, &new_sprite.y);
	if (!new_sprite.xpm)
		error_message("Couldn't find a image.\n", game->map);
	return (new_sprite);
}
