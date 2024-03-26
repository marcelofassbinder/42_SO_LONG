/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:31:07 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/26 13:03:47 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	has_valid_path(t_map map)
{
	char		**dup;
	int			i;
	t_position	player;

	dup = ft_calloc(sizeof(char *), map.line + 1);
	if (!dup)
		free_map(dup);
	i = 0;
	while(map.map_array[i])
	{
		dup[i] = ft_strdup(map.map_array[i]);
		i++;
	}
	player = player_position(map);
	if (valid_path(map, player.y, player.x, dup) == 1)
	{
		free_map(dup);
		return (1);
	}
	free_map(dup);
	return (0);
}

int valid_path(t_map map, int y, int x, char **copy)
{
	static int counter = 0;
	static int found_exit = 0;
	
	if (y < 0 || x < 0 || y >= map.line || x >= map.column)
		return (0);
	if (copy[y][x] == EXIT)
		found_exit = 1;
	if (counter == map.coins && found_exit == 1)
		return(1);
	if (copy[y][x] == WALL)
		return (0);
	if (copy[y][x] == COLLECTIBLE)
		counter++;
	copy[y][x] = WALL;
	if (valid_path(map, y + 1, x, copy)
		|| valid_path(map, y - 1, x, copy)
		|| valid_path(map, y, x + 1, copy)
		|| valid_path(map, y, x - 1, copy))
		return (1);
	return (0);
}
