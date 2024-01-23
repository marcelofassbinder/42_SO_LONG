/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:56:00 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/23 18:20:07 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map map)
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
}
void	free_game(t_game game)
{
	void	*mlx;

	mlx = game.mlx_ptr;
	mlx_destroy_image(mlx, game.floor.xpm);
	mlx_destroy_image(mlx, game.collectible.xpm);
	mlx_destroy_image(mlx, game.exit.xpm);
	mlx_destroy_image(mlx, game.player_up.xpm);
	mlx_destroy_image(mlx, game.player_down.xpm);
	mlx_destroy_image(mlx, game.player_right.xpm);
	mlx_destroy_image(mlx, game.player_left.xpm);
	free_map(game.map);
	mlx_destroy_window(mlx, game.mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
}
int	error_message(char *str, t_map map)
{
	free_map(map);
	return(ft_printf(2, "Error!\n%s", str));
}
