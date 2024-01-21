/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:08:16 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/21 18:32:00 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;
	int		fd;

	(void)game;
	if(check_input(argc, argv) != 1)
		exit(2);
	fd = open(argv[1], O_RDONLY);
	map = init_map(fd);
	if(check_map(map) == 1)
		print_map(map);
	game = init_game(map);
	render_first_image(game);

}	
