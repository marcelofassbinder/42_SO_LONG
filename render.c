/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:35:08 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/19 17:02:46 by mfassbin         ###   ########.fr       */
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
	print_movements(game);
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
	{
		if (game->map.coins > 0 && game->map.map_array[game->map.player_position.y][game->map.player_position.x] == EXIT)
			render_sprite(game, game->exit_closed, y, x);
		else
			render_sprite(game, game->exit, y, x);
	}
	else if (map_char == COLLECTIBLE)
		render_sprite(game, game->collectible, y, x);
	else if (map_char == PLAYER)
		render_sprite(game, game->player_current, y, x);
}

void	print_movements(t_game *game)
{
	char *str;
	char *count;

	count = ft_itoa(game->count_moves);
	str = ft_strjoin("SPONGEBOB MOVEMENTS: ", count);
	ft_printf(1, "%s\n", str);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 40, 29, 99999, str);
	free(count);
	free(str);
}
