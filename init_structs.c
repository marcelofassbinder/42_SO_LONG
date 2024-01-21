/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:21:42 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/21 18:36:57 by mfassbin         ###   ########.fr       */
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

void	render_first_image(t_game game)
{
	int	line;
	int	column;

	line = 0;
	while(line < game.map.line)
	{
		column = 0;
		while(column < game.map.column)
		{
			render_sprite(game, column, line);
			column += SIZE;
		}
		line += SIZE;
	}
}

void	render_sprite(t_game game, int y, int x)
{
	char	**map_array;

	map_array = game.map.map_array;
	if (map_array[y][x] == WALL)
		mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.wall.xpm, x, y);
	else if (map_array[y][x] == EMPTY)
		mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.floor.xpm, x, y);
	else if (map_array[y][x] == EXIT)
		mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.exit.xpm, x, y);
	else if (map_array[y][x] == COLLECTIBLE)
		mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.collectible.xpm, x, y);
	else if (map_array[y][x] == PLAYER)
		mlx_put_image_to_window(game.mlx_ptr, game.mlx_win, game.player_right.xpm, x, y);
}
t_game	init_game(t_map map)
{	
	t_game	game;

	game.map = map;
	game.mlx_ptr = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx_ptr, (map.column * SIZE), (map.line * SIZE), "so_long");
	mlx_loop(game.mlx_ptr);
	game.player_right = new_sprite(game, "./textures/character.xpm");
	return(game);
}

t_image	new_sprite(t_game game, char *path_to_xpm)
{
	t_image	new_sprite;

	new_sprite.xpm = mlx_xpm_file_to_image(game.mlx_ptr, path_to_xpm, (int *)SIZE, (int *)SIZE);
	return(new_sprite);	
}