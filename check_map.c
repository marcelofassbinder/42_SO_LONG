/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:21:10 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/20 16:35:17 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_map map)
{
	int i;

	if (map.line < 3 || map.column < 3)
		return(ft_printf(2, "Error! Map contains less than 3 lines/columns.\n"));
	i = 0;
	while(map.map_array[i])
	{
		if(ft_strlen(map.map_array[i]) != map.column)
			return(ft_printf(2, "Error! Map is not rectangular.\n"));
		i++;
	}
	if (count_appearance(map, PLAYER) != 1 || count_appearance(map, EXIT) != 1 || 
		count_appearance(map, COLLECTIBLE) < 1)
			return (ft_printf(2, "Error! Map must contain just 1 player, 1 exit and at least 1 collectible.\n"));
	if (!invalid_char(map))
		return(ft_printf(2, "Error! Invalid character found.\n"));
	if (!surrounded_by_walls(map))
		return(ft_printf(2, "Error! Map must be surrounded by walls.\n"));
	return (1);
}

int	count_appearance(t_map map, char c)
{
	int i;
	int j;
	int counter;
	char **map_array;

	map_array = map.map_array;
	counter = 0;
	i = 0;
	while(map_array[i])
	{
		j = 0;
		while(map_array[i][j])
		{
			if(map_array[i][j] == c)
				counter++;
			j++;
		}
		i++;
	}
	return(counter);
}

int invalid_char(t_map map)
{
	int i;
	int j;
	char **map_array;

	map_array = map.map_array;
	i = 0;
	while(map_array[i])
	{
		j = 0;
		while(map_array[i][j])
		{
			if(map_array[i][j] != WALL && map_array[i][j] != EMPTY && 
				map_array[i][j] != PLAYER && map_array[i][j] != EXIT &&
					map_array[i][j] != COLLECTIBLE)
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}
int	surrounded_by_walls(t_map map)
{
	int i;
	int j;
	char **map_array;

	map_array = map.map_array;
	j = 0;
	while(map_array[0][j])
	{
		if(map_array[0][j] != WALL || map_array[map.line - 1][j] != WALL)
			return(0);
		j++;
	}
	i = 0;
	while(i < map.line)
	{
		if(map_array[i][0] != WALL || map_array[i][map.column - 1] != WALL)
			return(0);
		i++;
	}
	return (1);
}

