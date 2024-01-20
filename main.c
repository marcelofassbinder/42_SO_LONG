/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:08:16 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/20 14:38:49 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	/* void	*mlx;
	void	*mlx_win; */
	t_map	map;
	int		fd;

/* 	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "so_long");
	mlx_loop(mlx); */
	if(check_input(argc, argv) == 1)
	{
		fd = open(argv[1], O_RDONLY);
		map = init_map(fd);
		if(check_map(map) == 1)
			print_map(map);
	}
}
