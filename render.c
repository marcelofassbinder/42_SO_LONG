/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:35:08 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/25 16:55:32 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while(y < game->map.line)
	{
		x = 0;
		while(x < game->map.column)
		{
			identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
}

void	render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, sprite.xpm, column * SIZE, line * SIZE);
}

void	identify_sprite(t_game *game, int y, int x)
{
	char	map_char;

	map_char = game->map.map_array[y][x];
	if (map_char == WALL)
		render_sprite(game, game->wall, y, x);
	else if (map_char == EMPTY)
		render_sprite(game, game->floor, y, x);
	else if (map_char == EXIT)
		render_sprite(game, game->exit, y, x);
	else if (map_char == COLLECTIBLE)
		render_sprite(game, game->collectible, y, x);
	else if (map_char == PLAYER)
		render_sprite(game, game->player_current, y, x);
}

/* void	render_player(t_game game, ) */
