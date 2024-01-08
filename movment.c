/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:31:49 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/08 14:42:52 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_up(t_map *map_s, t_data *img)
{
	if (map_s->map[map_s->p_y][map_s->p_x] != 'P')
		return ;
	if (map_s->map[map_s->p_y - 1][map_s->p_x] == '0')
	{
		map_s->map[map_s->p_y - 1][map_s->p_x] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
	}
	else if (map_s->map[map_s->p_y - 1][map_s->p_x] == 'C')
	{
		map_s->map[map_s->p_y - 1][map_s->p_x] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
	}
	else if (map_s->map[map_s->p_y - 1][map_s->p_x] == 'E'
			&& !ft_collectable_count(map_s->map))
	{
		map_s->map[map_s->p_y - 1][map_s->p_x] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
		ft_quit_game(img);
	}
}

void	ft_right(t_map *map_s, t_data *img)
{
	if (map_s->map[map_s->p_y][map_s->p_x] != 'P')
		return ;
	map_s->p_s = 1;
	if (map_s->map[map_s->p_y][map_s->p_x + 1] == '0')
	{
		map_s->map[map_s->p_y][map_s->p_x + 1] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
	}
	else if (map_s->map[map_s->p_y][map_s->p_x + 1] == 'C')
	{
		map_s->map[map_s->p_y][map_s->p_x + 1] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
	}
	else if (map_s->map[map_s->p_y][map_s->p_x + 1] == 'E'
			&& !ft_collectable_count(map_s->map))
	{
		map_s->map[map_s->p_y][map_s->p_x + 1] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
		ft_quit_game(img);
	}
}

void	ft_left(t_map *map_s, t_data *img)
{
	if (map_s->map[map_s->p_y][map_s->p_x] != 'P')
		return ;
	map_s->p_s = 2;
	if (map_s->map[map_s->p_y][map_s->p_x - 1] == '0')
	{
		map_s->map[map_s->p_y][map_s->p_x - 1] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
	}
	else if (map_s->map[map_s->p_y][map_s->p_x - 1] == 'C')
	{
		map_s->map[map_s->p_y][map_s->p_x - 1] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
	}
	else if (map_s->map[map_s->p_y][map_s->p_x - 1] == 'E'
			&& !ft_collectable_count(map_s->map))
	{
		map_s->map[map_s->p_y][map_s->p_x - 1] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
		ft_quit_game(img);
	}
}

void	ft_down(t_map *map_s, t_data *img)
{
	if (map_s->map[map_s->p_y][map_s->p_x] != 'P')
		return ;
	map_s->p_s = 0;
	if (map_s->map[map_s->p_y + 1][map_s->p_x] == '0')
	{
		map_s->map[map_s->p_y + 1][map_s->p_x] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
	}
	else if (map_s->map[map_s->p_y + 1][map_s->p_x] == 'C')
	{
		map_s->map[map_s->p_y + 1][map_s->p_x] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
	}
	else if (map_s->map[map_s->p_y + 1][map_s->p_x] == 'E'
			&& !ft_collectable_count(map_s->map))
	{
		map_s->map[map_s->p_y + 1][map_s->p_x] = 'P';
		map_s->map[map_s->p_y][map_s->p_x] = '0';
		img->moves++;
		ft_quit_game(img);
	}
}
