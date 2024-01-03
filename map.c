/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:03:58 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/03 10:19:32 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		while (map[y][x] && map[y][x] != '1')
			x++;
		if (map[y][x] && map[y][x] == '1')
		{
			while (map[y][x] && (map[y][x] == '1' ||
			map[y][x] == '0' || map[y][x] == 'C' ||
			map[y][x] == 'P' || map[y][x++] == 'E'))
				x++;
			if (tmp > 0 || tmp < 0)
				exit(ft_putstr("its not rectangular"));
		}
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

int	ft_check_map(char **map)
{
	int	line_length;

	line_length = ft_firstline(map);
	if (!map)
		exit(ft_putstr("THER'S NO MAP"));
	else if (ft_exits(map))
		exit (0);
	else if (ft_collectable(map))
		exit (0);
	else if (ft_player(map))
		exit (0);
	else if (ft_rectangular_check(map, line_length))
		exit (0);
	return (0);
}
