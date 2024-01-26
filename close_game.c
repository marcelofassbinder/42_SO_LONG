/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:10:57 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/26 12:24:22 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_game *game, int victory)
{
	if (victory == 1)
		ft_printf(1, "CONGRATULATIONS! YOU WON! :D\n");
	else
	{
		ft_printf(1, "The key %i has been pressed.\n", ESC);
		ft_printf(1, "You closed the game.\n");
	}
	free_game(game);
	exit(1);
}

