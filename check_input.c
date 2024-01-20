/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:55:30 by mfassbin          #+#    #+#             */
/*   Updated: 2024/01/20 14:28:30 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int argc, char **argv)
{
	int	fd;
	
	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		return(ft_printf(2, "Error! Invalid number of arguments.\n"));
	else if (!check_extension(argv[1]) || fd < 0)
		return(ft_printf(2, "Error! Invalid file.\n"));
	return(1);
}

int	check_extension(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	while(str[len] != '.')
		len--;
	if (len == 0)
		return (0);
	if(ft_strncmp(&str[len], ".ber", 5) == 0)
		return (1);
	else
		return (0);
}
