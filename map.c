/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:08:36 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/20 16:24:28 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd)
{
	char	*line;
	char	*map_str;
	char	**map;

	map_str = ft_strdup("");
	while(1)
	{
		line = get_next_line(fd);
		if(line == NULL)
			break;
		map_str = ft_strjoin2(map_str, line);
		free(line);
	}
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}

void	print_map(t_map map)
{
	int i;

	i = 0;
	while(map.map_array[i])
	{
		ft_printf(1, "%s\n", map.map_array[i]);
		i++;
	}
	ft_printf(1, "lines = %i\n", map.line);
	ft_printf(1, "columns = %i\n", map.column);
}

int	count_lines(char **map)
{
	int line;

	line = 0;
	while(map[line])
		line++;
	return(line);
}

int count_columns(char **map)
{
	return(ft_strlen(map[0]));
}
