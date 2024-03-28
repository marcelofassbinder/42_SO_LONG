/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:21:10 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/28 18:30:10 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Checks if map contain more than 3 lines/columns, exactly 1 player, 1 exit and 
at least 1 collectible; if there is a invalid char in the array;if the map is 
totally surrounded by walls; if there is a valid path; and if the map is 
rectangular*/
/*Returns 1 if the map is valid, or returns a specific error message describing 
the issue encountered.*/
int	check_map(t_map map)
{
	int	i;

	if (map.line < 3 || map.column < 3)
		return (error_message("Map must contain more \
		than 3 lines/columns.\n", map));
	else if (map.players != 1 || map.exit != 1 || map.coins < 1)
		return (error_message("Map must contain just 1 player, \
		1 exit and at least 1 collectible.\n", map));
	else if (!invalid_char(map))
		return (error_message("Invalid character found.\n", map));
	else if (!surrounded_by_walls(map))
		return (error_message("Map must be surrounded by walls.\n", map));
	else if (!has_valid_path(map))
		return (error_message("Map must contain a valid path.\n", map));
	i = 0;
	while (map.map_array[i])
	{
		if (ft_strlen(map.map_array[i]) != map.column)
			return (error_message("Map is not rectangular.\n", map));
		i++;
	}
	return (1);
}

/*Counts how many times a specific character appears in the map array*/
/*Returns how many times char 'c' appears in the map array*/
int	count_appearance(t_map map, char c)
{
	char	**map_array;
	int		i;
	int		j;
	int		counter;

	map_array = map.map_array;
	counter = 0;
	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] == c)
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}

/*Checks if the map array contains any invalid characters. 
Valid characters are 'P', 'C', 'E', '0', and '1'.*/
/*Returns 0 if the map array contains an invalid character, 
or 1 to indicate success.*/
int	invalid_char(t_map map)
{
	char	**map_array;
	int		i;
	int		j;

	map_array = map.map_array;
	i = 0;
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			if (map_array[i][j] != WALL && map_array[i][j] != EMPTY &&
				map_array[i][j] != PLAYER && map_array[i][j] != EXIT &&
					map_array[i][j] != COLLECTIBLE)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*Checks if the map is all surrounded by walls.*/
/*Returns 0 if map contains anything different from wall, 
or 1, indicating success*/
int	surrounded_by_walls(t_map map)
{
	char	**map_array;
	int		i;
	int		j;

	map_array = map.map_array;
	j = 0;
	while (map_array[0][j])
	{
		if (map_array[0][j] != WALL || map_array[map.line - 1][j] != WALL)
			return (0);
		j++;
	}
	i = 0;
	while (i < map.line)
	{
		if (map_array[i][0] != WALL || map_array[i][map.column - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}
