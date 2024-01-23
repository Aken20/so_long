/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:31:49 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 14:30:34 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_handle(t_data *img, char c1, char c2, int i)
{
	if (i == 1)
	{
		img->map_s->map[img->map_s->p_y + 1][img->map_s->p_x] = c1;
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = c2;
		img->moves++;
	}
	if (i == 2)
	{
		img->map_s->map[img->map_s->p_y - 1][img->map_s->p_x] = c1;
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = c2;
		img->moves++;
	}
	if (i == 3)
	{
		img->map_s->map[img->map_s->p_y][img->map_s->p_x + 1] = c1;
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = c2;
		img->moves++;
	}
	if (i == 4)
	{
		img->map_s->map[img->map_s->p_y][img->map_s->p_x - 1] = c1;
		img->map_s->map[img->map_s->p_y][img->map_s->p_x] = c2;
		img->moves++;
	}
}

void	ft_up(t_map *map_s, t_data *img)
{
	if (map_s->map[map_s->p_y][map_s->p_x] != 'P'
		&& map_s->map[map_s->p_y][map_s->p_x] != 'A')
		return ;
	if (map_s->map[map_s->p_y - 1][map_s->p_x] == 'L'
		|| map_s->map[map_s->p_y - 1][map_s->p_x] == 'R')
		ft_quit_game(img);
	else if (map_s->map[map_s->p_y][map_s->p_x] == 'A'
		&& map_s->map[map_s->p_y - 1][map_s->p_x] != '1')
		ft_handle(img, 'P', 'E', 2);
	else if (map_s->map[map_s->p_y - 1][map_s->p_x] == '0'
			|| map_s->map[map_s->p_y - 1][map_s->p_x] == 'C')
		ft_handle(img, 'P', '0', 2);
	else if (map_s->map[map_s->p_y - 1][map_s->p_x] == 'E')
	{
		if (ft_collectable_count(map_s->map))
			ft_handle(img, 'A', '0', 2);
		else
		{
			ft_handle(img, 'P', '0', 2);
			ft_quit_game(img);
		}
	}
}

void	ft_right(t_map *map_s, t_data *img)
{
	if (map_s->map[map_s->p_y][map_s->p_x] != 'P'
		&& map_s->map[map_s->p_y][map_s->p_x] != 'A')
		return ;
	map_s->p_s = 1;
	if (map_s->map[map_s->p_y][map_s->p_x + 1] == 'L'
		|| map_s->map[map_s->p_y][map_s->p_x + 1] == 'R')
		ft_quit_game(img);
	else if (map_s->map[map_s->p_y][map_s->p_x] == 'A'
		&& map_s->map[map_s->p_y][map_s->p_x + 1] != '1')
		ft_handle(img, 'P', 'E', 3);
	else if (map_s->map[map_s->p_y][map_s->p_x + 1] == '0'
			|| map_s->map[map_s->p_y][map_s->p_x + 1] == 'C')
		ft_handle(img, 'P', '0', 3);
	else if (map_s->map[map_s->p_y][map_s->p_x + 1] == 'E')
	{
		if (ft_collectable_count(map_s->map))
			ft_handle(img, 'A', '0', 3);
		else
		{
			ft_handle(img, 'P', '0', 3);
			ft_quit_game(img);
		}
	}
}

void	ft_left(t_map *map_s, t_data *img)
{
	if (map_s->map[map_s->p_y][map_s->p_x] != 'P'
		&& map_s->map[map_s->p_y][map_s->p_x] != 'A')
		return ;
	map_s->p_s = 2;
	if (map_s->map[map_s->p_y][map_s->p_x - 1] == 'L'
		|| map_s->map[map_s->p_y][map_s->p_x - 1] == 'R')
		ft_quit_game(img);
	else if (map_s->map[map_s->p_y][map_s->p_x] == 'A'
		&& map_s->map[map_s->p_y][map_s->p_x - 1] != '1')
		ft_handle(img, 'P', 'E', 4);
	else if (map_s->map[map_s->p_y][map_s->p_x - 1] == '0'
			|| map_s->map[map_s->p_y][map_s->p_x - 1] == 'C')
		ft_handle(img, 'P', '0', 4);
	else if (map_s->map[map_s->p_y][map_s->p_x - 1] == 'E')
	{
		if (ft_collectable_count(map_s->map))
			ft_handle(img, 'A', '0', 4);
		else
		{
			ft_handle(img, 'P', '0', 4);
			ft_quit_game(img);
		}
	}
}

void	ft_down(t_map *map_s, t_data *img)
{
	if (map_s->map[map_s->p_y][map_s->p_x] != 'P'
		&& map_s->map[map_s->p_y][map_s->p_x] != 'A')
		return ;
	map_s->p_s = 0;
	if (map_s->map[map_s->p_y + 1][map_s->p_x] == 'L'
		|| map_s->map[map_s->p_y + 1][map_s->p_x] == 'R')
		ft_quit_game(img);
	else if (map_s->map[map_s->p_y][map_s->p_x] == 'A'
		&& map_s->map[map_s->p_y + 1][map_s->p_x] != '1')
		ft_handle(img, 'P', 'E', 1);
	else if (map_s->map[map_s->p_y + 1][map_s->p_x] == '0'
		|| map_s->map[map_s->p_y + 1][map_s->p_x] == 'C')
		ft_handle(img, 'P', '0', 1);
	else if (map_s->map[map_s->p_y + 1][map_s->p_x] == 'E')
	{
		if (ft_collectable_count(map_s->map))
			ft_handle(img, 'A', '0', 1);
		else
		{
			ft_handle(img, 'P', '0', 1);
			ft_quit_game(img);
		}
	}
}
