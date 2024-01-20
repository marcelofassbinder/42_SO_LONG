/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:21:42 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/20 13:29:40 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	init_map(int fd)
{
	t_map	map;
	map.map_array = read_map(fd);
	map.line = count_lines(map.map_array);
	map.column = count_columns(map.map_array);
	return(map);
}
