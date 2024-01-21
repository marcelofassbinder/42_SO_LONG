/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:56:00 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/21 16:11:12 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_message(char *str, t_map map)
{
	char **map_array;
	int i;

	map_array = map.map_array;
	i = 0;
	while(map_array[i])
	{
		free(map_array[i]);
		i++;
	}
	free(map_array);
	return(ft_printf(2, "Error!\n%s", str));
}