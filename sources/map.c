/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:08:36 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/28 18:36:23 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*Creates an array, using "get_next_line" containing all the characters present
on the file .ber, which file descriptor is passed as parameter*/
/*Returns the map array, or if an empty line is encountered, exit the program, 
indicating failure*/
char	**read_map(int fd)
{
	char	*line;
	char	*map_str;
	char	**map;

	map_str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_str = ft_strjoin2(map_str, line);
		free(line);
	}
	if (check_for_empty_line(map_str) == 1)
	{
		map = ft_split(map_str, '\n');
		free(map_str);
		return (map);
	}
	exit(EXIT_FAILURE);
}

/*Checks if the map array contains an empty line.*/
/*Return 1 if the map is valid, or in case of failure,
returns an error message*/
int	check_for_empty_line(char *map_str)
{
	int		i;

	if (map_str[0] == '\n' || map_str[0] == '\0'
		|| map_str[ft_strlen(map_str) - 1] == '\n')
	{
		free(map_str);
		return (ft_printf(2, "Error!\nMap contains empty line.\n"));
	}
	i = 0;
	while (map_str[i])
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
		{
			free(map_str);
			return (ft_printf(2, "Error!\nMap contains empty line.\n"));
		}
		i++;
	}
	return (1);
}

/*Counts how many lines are in the map array.*/
/*Returns the quantity of lines.*/
int	count_lines(char **map)
{
	int	line;

	line = 0;
	while (map[line])
		line++;
	return (line);
}

/*Using recursion, this function checks if there is a possible way for the
player to collect all the coins before reaching the exit. It explores the map 
step-by-step trying to move to all the directions, to make sure there is a 
valid path.
To avoid re-exploring the same place, the function "paints" 
that position with "WALL", so those coordinates will not be reached again.*/
/*Returns 1 only if the exit and all the collectibles were reached. 
Otherwise, it returns 0. */
int	valid_path(t_map map, int y, int x, char **copy)
{
	static int	counter = 0;
	static int	found_exit = 0;

	if (y < 0 || x < 0 || y >= map.line || x >= map.column)
		return (0);
	if (copy[y][x] == EXIT)
		found_exit = 1;
	if (counter == map.coins && found_exit == 1)
		return (1);
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

/*Creates a copy of map array, to pass as a parameter into 
"valid_path" function*/
/*Returns 1 if the map has a valid path (the player can collect all the 
coins and reach the exit), or 0 if not.*/
int	has_valid_path(t_map map)
{
	char		**dup;
	int			i;
	t_position	player;

	dup = ft_calloc(sizeof(char *), map.line + 1);
	if (!dup)
		free_map(dup);
	i = 0;
	while (map.map_array[i])
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
