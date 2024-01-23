/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:38:14 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 14:32:28 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit_game(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	ft_free_all(img, 1);
	return (0);
}

int	ft_is_valid(char **map, int y, int x)
{
	if (map[y][x] && (map[y][x] == '1' ||
			map[y][x] == '0' || map[y][x] == 'C' ||
			map[y][x] == 'P' || map[y][x] == 'E'))
		return (1);
	return (0);
}

int	ft_collectable_count(char **map)
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
	return (collectable);
}

static	void	ft_player(t_data *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (img->map_tmp->map[y])
	{
		while (img->map_tmp->map[y][x])
		{
			if (img->map_tmp->map[y][x] == 'P')
			{
				img->map_tmp->p_x = x;
				img->map_tmp->p_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

int	ft_valid_path(t_data *img, int x, int y)
{
	if (x == 0 && y == 0)
	{
		ft_player(img);
		x = img->map_tmp->p_x;
		y = img->map_tmp->p_y;
		img->map_tmp->p_s = 0;
	}
	if (!ft_exit_count(img->map_tmp->map)
		&& !(ft_collectable_count(img->map_tmp->map)))
		img->map_tmp->p_s = 1;
	if (img->map_tmp->map[y][x] != '1')
	{
		img->map_tmp->map[y][x] = '1';
		if (y > 0)
			ft_valid_path(img, x, y - 1);
		if (y < img->map_s->y)
			ft_valid_path(img, x, y + 1);
		if (x > 0)
			ft_valid_path(img, x - 1, y);
		if (x < img->map_s->x)
			ft_valid_path(img, x + 1, y);
	}
	return (img->map_tmp->p_s);
}
