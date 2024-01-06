/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:03:58 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/06 23:06:25 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_valid(char **map, int y, int x)
{
	if (map[y][x] && (map[y][x] == '1' ||
			map[y][x] == '0' || map[y][x] == 'C' ||
			map[y][x] == 'P' || map[y][x] == 'E'))
		return (1);
	return (0);
}

static	int	ft_rectangular_check(char **map, int len)
{
	int	x;
	int	y;
	int	tmp;

	x = 0;
	y = 0;
	while (map[y])
	{
		tmp = len;
		if (map[y][x] && map[y][x] == '1')
		{
			while (ft_is_valid(map, y, x++))
				tmp--;
		}
		if (tmp != 0 && map[y][x] != '\n')
			exit(ft_putstr("its not rectangular"));
		x = 0;
		y++;
	}
	return (0);
}

static	int	ft_collectable(char **map)
{
	int	collectable;
	int	y;
	int	x;

	collectable = 0;
	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collectable++;
			x++;
		}
		x = 0;
		y++;
	}
	if (collectable < 1)
		return (ft_putstr("LESS THAN ONE COLLECTABLE"));
	return (0);
}

static	int	ft_exits(char **map)
{
	int	exit;
	int	y;
	int	x;

	exit = 0;
	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				exit++;
			x++;
		}
		x = 0;
		y++;
	}
	if (exit > 1)
		return (ft_putstr("MORE THAN ONE EXIT"));
	else if (exit == 0)
		return (ft_putstr("THER'S NO EXIT"));
	return (0);
}

static	int	ft_player(char **map)
{
	int	player;
	int	y;
	int	x;

	player = 0;
	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player++;
			x++;
		}
		x = 0;
		y++;
	}
	if (player > 1)
		return (ft_putstr("MORE THAN ONE PLAYER"));
	if (player <= 0)
		return (ft_putstr("THER'S NO PLAYER"));
	return (0);
}

int	ft_check_map(t_data *img)
{
	int	line_length;
	int	len;

	len = 0;
	if (!img->map_s->map)
		exit(ft_putstr("THER'S NO MAP"));
	line_length = ft_firstline(img->map_s->map);
	while (img->map_s->map[len])
		len++;
	ft_lastline(img->map_s->map[len - 1], line_length);
	if (ft_exits(img->map_s->map))
		exit (0);
	else if (ft_collectable(img->map_s->map))
		exit (0);
	if (ft_player(img->map_s->map))
		exit (0);
	if (ft_rectangular_check(img->map_s->map, line_length))
		exit (0);
	if (ft_check_sides(img->map_s->map, line_length))
		return (0);
	return (0);
}
