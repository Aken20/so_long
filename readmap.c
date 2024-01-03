/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 04:27:23 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/03 10:15:59 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lines_len(char *s, int fd)
{
	int	len;

	len = 0;
	s = get_next_line(fd);
	while (s)
	{
		if (!s)
			break ;
		s = get_next_line(fd);
		len++;
		free(s);
	}
	return (len);
}

int	ft_firstline(char **map)
{
	int	x;
	int	y;
	int	len;
	int	c;

	x = 0;
	y = 0;
	len = 0;
	c = 0;
	if (map[y][x])
	{
		while (map[y][x] && map[y][x] != '1')
			x++;
		while (map[y][x] && map[y][x++] == '1')
			len++;
		y++;
	}
	return (len);
}

char	**ft_read_map(char **map, char *file)
{
	int				fd;
	int				i;
	char			*s;

	i = 0;
	fd = open(file, O_RDONLY);
	i = ft_lines_len(s, fd);
	map = malloc (sizeof(char *) * (i + 1));
	i = 0;
	close(fd);
	fd = open(file, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		if (!s)
			break ;
		map[i] = ft_g_strdup(s, 0);
		s = get_next_line(fd);
		i++;
		free(s);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
