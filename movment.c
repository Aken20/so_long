/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:31:49 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/06 15:06:58 by ahibrahi         ###   ########.fr       */
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

void	ft_up(t_data *img)
{
	if (img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] == '0')
	{
		img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
	}
	else if (img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] == 'C')
	{
		img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
	}
	else if (img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] == 'E'
			&& !ft_collectable_count(img->map_s->map))
	{
		img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
		ft_quit_game(img);
	}
}

void	ft_right(t_data *img)
{
	img->map_s->p_s = 1;
	if (img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] == '0')
	{
		img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
	}
	else if (img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] == 'C')
	{
		img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
	}
	else if (img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] == 'E'
			&& !ft_collectable_count(img->map_s->map))
	{
		img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
		ft_quit_game(img);
	}
}

void	ft_left(t_data *img)
{
	img->map_s->p_s = 2;
	if (img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] == '0')
	{
		img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
	}
	else if (img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] == 'C')
	{
		img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
	}
	else if (img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] == 'E'
			&& !ft_collectable_count(img->map_s->map))
	{
		img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
		ft_quit_game(img);
	}
}

void	ft_down(t_data *img)
{
	if (img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] == '0')
	{
		img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
	}
	else if (img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] == 'C')
	{
		img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
	}
	else if (img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] == 'E'
			&& !ft_collectable_count(img->map_s->map))
	{
		img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] = 'P';
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = '0';
		ft_quit_game(img);
	}
}
