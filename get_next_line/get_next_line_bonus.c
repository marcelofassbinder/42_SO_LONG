/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassbin <mfassbin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:58:39 by mfassbin          #+#    #+#             */
/*   Updated: 2023/11/10 14:32:55 by mfassbin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *dest)
{
	char	*buf;
	int		count_read;

	count_read = 1;
	while (nextline(dest) == 0 && count_read != 0)
	{
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		count_read = read(fd, buf, BUFFER_SIZE);
		if (count_read == 0)
		{
			free(buf);
			return (dest);
		}
		if (count_read == -1)
		{
			free(buf);
			free(dest);
			return (NULL);
		}
		dest = ft_strjoin(dest, buf);
		free(buf);
	}
	return (dest);
}

char	*clean_line(char *dest)
{
	char	*line;
	int		next;

	next = nextline(dest);
	if (next == 0)
		next = ft_strlen(dest);
	if (next == 0)
		return (NULL);
	line = ft_calloc(sizeof(char), (next + 1));
	if (!line)
	{
		free (dest);
		return (NULL);
	}
	ft_strlcpy(line, dest, next + 1);
	return (line);
}

char	*new_dest(char *dest)
{
	char	*new_dest;
	int		i;
	int		len;

	len = ft_strlen(dest);
	i = nextline(dest);
	if (i == 0 || len == 0)
	{
		free (dest);
		return (NULL);
	}
	new_dest = ft_calloc(sizeof(char), len - i + 1);
	if (!new_dest)
	{
		free(dest);
		return (NULL);
	}
	ft_strlcpy(new_dest, &dest[i], len - i + 1); 
	free(dest);
	return (new_dest);
}

char	*get_next_line(int fd)
{
	static char		*dest[1024]; 
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dest[fd] = read_line(fd, dest[fd]);
	if (!dest[fd])
		return (NULL);
	line = clean_line(dest[fd]);
	dest[fd] = new_dest(dest[fd]);
	return (line);
}
/*  #include <stdio.h>
#include <fcntl.h>

int main()
{
	char *r;
	char *t;

	int fdr = open("read_error.txt", O_RDONLY);
	int fdt = open("teste.txt", O_RDONLY);
	
	printf(" 1r %s", get_next_line(fdr));
	
	printf(" 1t %s", get_next_line(fdt));

	printf(" 2r %s", get_next_line(fdr));

	printf(" 2t %s", get_next_line(fdt));

	printf(" 3r %s", get_next_line(fdr));

	printf(" 3t %s", get_next_line(fdt));
	
	printf(" 4r %s", get_next_line(fdr));
	
	printf(" 4t %s", get_next_line(fdt));

}  */