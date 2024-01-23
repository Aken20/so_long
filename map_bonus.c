/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:03:58 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 06:30:30 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		if (tmp != 0 || map[y][x - 1] != '\0')
			return (ft_putstr("its not rectangular"));
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
		return (ft_putstr("LESS THAN ONE COLLECTABLE\n"));
	return (0);
}

int	ft_exits(char **map)
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
		return (ft_putstr("MORE THAN ONE exit\n"));
	if (exit <= 0)
		return (ft_putstr("THER'S NO exit\n"));
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
			if (map[y][x] == 'P' || map[y][x] == 'A')
				player++;
			x++;
		}
		x = 0;
		y++;
	}
	if (player > 1)
		return (ft_putstr("MORE THAN ONE PLAYER\n"));
	if (player <= 0)
		return (ft_putstr("THER'S NO PLAYER\n"));
	return (0);
}

int	ft_check_map(t_data *img)
{
	int	line_length;
	int	len;

	len = 0;
	if (!img->map_s->map)
		return (0);
	line_length = ft_firstline(img->map_s->map[0]);
	while (img->map_s->map[len])
		len++;
	if (len <= 1)
		return (0);
	ft_lastline(img->map_s->map[len - 1], line_length);
	if (ft_exits(img->map_s->map))
		return (0);
	if (ft_collectable(img->map_s->map))
		return (0);
	if (ft_player(img->map_s->map))
		return (0);
	if (ft_rectangular_check(img->map_s->map, line_length))
		return (0);
	if (ft_check_sides(img->map_s->map, line_length))
		return (0);
	return (1);
}
