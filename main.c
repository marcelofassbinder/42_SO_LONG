/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:08:16 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/22 16:35:00 by mfassbin         ###   ########.fr       */
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
	render_map(game);
	mlx_loop(game.mlx_ptr);
/* 
	char *path;
	int x;
	int y;

	path = "textures/parede.xpm";
	void	*mlx = mlx_init();
	void	*mlx_win = mlx_new_window(mlx, 600, 600, "ola");
	void	*xpm_img = mlx_xpm_file_to_image(mlx, path, &x, &y);
	mlx_put_image_to_window(mlx, mlx_win, xpm_img, 50, 50);
	mlx_loop(mlx); */

}	
