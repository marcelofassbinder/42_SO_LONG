/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:56:00 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/21 18:30:10 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
void	free_game(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	mlx_destroy_image(mlx, game->floor.xpm);
	mlx_destroy_image(mlx, game->wall.xpm);
	mlx_destroy_image(mlx, game->collectible.xpm);
	mlx_destroy_image(mlx, game->exit.xpm);
	mlx_destroy_image(mlx, game->exit_closed.xpm);
	mlx_destroy_image(mlx, game->player_up.xpm);
	mlx_destroy_image(mlx, game->player_down.xpm);
	mlx_destroy_image(mlx, game->player_right.xpm);
	mlx_destroy_image(mlx, game->player_left.xpm);
	free_map(game->map.map_array);
	mlx_destroy_window(mlx, game->mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
	free(game);
}
int	error_message(char *str, t_map map)
{
	free_map(map.map_array);
	return(ft_printf(2, "Error!\n%s", str));
}
