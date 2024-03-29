/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_jelly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:17:27 by marcelo           #+#    #+#             */
/*   Updated: 2024/03/27 14:21:12 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	change_jelly_pos(t_game *game, int y, int x, int dir)
{
	if (dir == 0 && game->map.map_array[y - 1][x] == EMPTY)
	{
		game->map.map_array[y][x] = EMPTY;
		game->map.map_array[y - 1][x] = JELLY;
	}
	else if (dir == 1 && game->map.map_array[y + 1][x] == EMPTY)
	{
		game->map.map_array[y][x] = EMPTY;
		game->map.map_array[y + 1][x] = JELLY;
	}
	else if (dir == 2 && game->map.map_array[y][x + 1] == EMPTY)
	{
		game->map.map_array[y][x] = EMPTY;
		game->map.map_array[y][x + 1] = JELLY;
	}
	else if (dir == 3 && game->map.map_array[y][x - 1] == EMPTY)
	{
		game->map.map_array[y][x] = EMPTY;
		game->map.map_array[y][x - 1] = JELLY;
	}
}

void	move_jelly(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map_array[i])
	{
		j = 0;
		while (game->map.map_array[i][j])
		{
			if (game->map.map_array[i][j] == JELLY)
				change_jelly_pos(game, i, j, rand() % 4);
			j++;
		}
		i++;
	}
}
