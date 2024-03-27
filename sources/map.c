/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:08:36 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/27 14:05:08 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

t_position	player_position(t_map map)
{
	t_position	player_pos;
	char		**map_array;
	int			x;
	int			y;

	map_array = map.map_array;
	y = 0;
	while (y < map.line)
	{
		x = 0;
		while (x < map.column)
		{
			if (map_array[y][x] == PLAYER)
			{
				player_pos.x = x;
				player_pos.y = y;
			}
			x++;
		}
		y++;
	}
	return (player_pos);
}

int	count_lines(char **map)
{
	int	line;

	line = 0;
	while (map[line])
		line++;
	return (line);
}

void	print_map(t_map map)
{
	int	i;

	i = 0;
	while (map.map_array[i])
	{
		ft_printf(1, "%s\n", map.map_array[i]);
		i++;
	}
}
