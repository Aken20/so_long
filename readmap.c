/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 04:27:23 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 13:15:37 by ahibrahi         ###   ########.fr       */
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
		len++;
		if (!s)
			break ;
		free(s);
		s = get_next_line(fd);
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
				if (map[y][x - 1] != '1')
					return (ft_putstr("THE MAP ARE NOT SURROUNDED BY WALLS"));
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
	if (map && map != NULL)
	{
		while (map[x] && map[x] == '1')
		{
			len--;
			x++;
		}
		if (len != 0)
			return (ft_putstr("your map is not valid"));
	}
	return (0);
}

int	ft_firstline(char *map)
{
	int	x;
	int	len;

	x = 0;
	len = 0;
	if (map && map != NULL)
	{
		while (map[x] && map[x] == '1')
		{
			len++;
			x++;
		}
	}
	return (len);
}

void	ft_read_map(t_data *img, t_map *map, char *file)
{
	int				fd;
	int				i;
	char			*s;

	i = 0;
	fd = open(file, O_RDONLY);
	i = ft_lines_len(fd);
	map->map = malloc (sizeof(char *) * (i + 1));
	i = 0;
	fd = open(file, O_RDONLY);
	s = ft_strtrim(get_next_line(fd), "\n");
	while (s)
	{
		if (!s)
			break ;
		map->map[i] = ft_g_strdup(s, 1);
		s = ft_strtrim(get_next_line(fd), "\n");
		i++;
	}
	map->map[i] = NULL;
	s = get_next_line(fd);
	ft_check_read(img, s, fd);
	close(fd);
}
