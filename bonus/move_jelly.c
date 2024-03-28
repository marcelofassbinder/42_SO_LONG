/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_jelly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:17:27 by marcelo           #+#    #+#             */
/*   Updated: 2024/03/28 18:23:05 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*Changes the jellyfish position based on the direction passed as 
parameter (0 = UP, 1 = DOWN, 2 = RIGHT, 3 = LEFT).
If the next coordinate is not "EMPTY", nothing will be performed.*/
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

/*Changes the jellyfish position randomly, by calling the "rand" function,
which generates a random number. By dividing this number by 4, we get a 
remainder between 0 and 3. This remainder determines which direction the 
jellyfish will move, making it unpredictable. */
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
