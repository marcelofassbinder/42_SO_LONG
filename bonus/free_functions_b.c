/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcelo <marcelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:56:00 by mfassbin          #+#    #+#             */
/*   Updated: 2024/03/27 14:14:56 by marcelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
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
	mlx_destroy_image(mlx, game->jellyfish.xpm);
	free_map(game->map.map_array);
	mlx_destroy_window(mlx, game->mlx_win);
	mlx_destroy_display(mlx);
	free(mlx);
	free(game);
}

int	error_message(char *str, t_map map)
{
	free_map(map.map_array);
	return (ft_printf(2, "Error!\n%s", str));
}

void	close_game(t_game *game, int flag)
{
	if (flag == 1)
		ft_printf(1, "\033[42;37;5;1mCONGRATULATIONS! YOU WON! :D\033[0m\n");
	else if (flag == 0)
	{
		ft_printf(1, "The key %i has been pressed.\n", ESC);
		ft_printf(1, "\033[43;37;1mYou closed the game.\033[0m\n");
	}
	else if (flag == 2)
	{
		ft_printf(1, "The key %i has been pressed.\n", ESC);
		ft_printf(1, "\033[41;37;1mYou hit the jellyfish and died.\033[0m\n");
	}
	free_game(game);
	exit(EXIT_SUCCESS);
}
