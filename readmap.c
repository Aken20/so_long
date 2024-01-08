/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 04:27:23 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/08 12:38:50 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lines_len(int fd)
{
	char	*s;
	int		len;

	len = 0;
	s = get_next_line(fd);
	while (s)
	{
		if (!s)
			break ;
		s = get_next_line(fd);
		len++;
		// free(s);
	}
	return (len);
}

int	ft_check_sides(char **map, int len)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y] && y < len)
	{
		while (map[y][x])
		{
			if (map[y][x] == '1' || map[y][x] == '\n')
			{
				while (map[y][x])
					x++;
				if (x > 1)
					if (map[y][x - 1] != '1' && map[y][x - 1] != '\n')
						exit (ft_putstr("THE MAP ARE NOT SURROUNDED BY WALLS"));
			}
		}
		x = 0;
		y++;
	}
	return (0);
}

int	ft_lastline(char *map, int len)
{
	int	x;

	x = 0;
	if (map[x])
	{
		while (map[x] && map[x] == '1')
		{
			len--;
			x++;
		}
		if (len != 0)
			exit(ft_putstr("the first line and the last line is not all walls"));
	}
	return (0);
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
		while (map[y][x] && map[y][x] == '1')
		{
			len++;
			x++;
		}
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
	i = ft_lines_len(fd);
	if (i <= 0)
		exit(ft_putstr("THER'S NO FILE"));
	map = malloc (sizeof(char *) * (i + 1));
	i = 0;
	close(fd);
	fd = open(file, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		if (!s)
			break ;
		map[i++] = ft_g_strdup(s, 0);
		s = get_next_line(fd);
		// free(s);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
