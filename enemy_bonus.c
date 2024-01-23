/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:23:16 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 14:35:05 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_hocks(int keycode, t_data *img)
{
	mlx_do_sync(img->mlx);
	if (keycode == 53)
		ft_quit_game(img);
	else if (keycode == 13 || keycode == 126)
		ft_up(img->map_s, img);
	else if (keycode == 0 || keycode == 123)
		ft_left(img->map_s, img);
	else if (keycode == 1 || keycode == 125)
		ft_down(img->map_s, img);
	else if (keycode == 2 || keycode == 124)
		ft_right(img->map_s, img);
	return (0);
}

void	ft_enemy_right(t_data *img)
{
	if (img->map_s->map[img->y][img->x] == 'R'
		&& img->map_s->map[img->y][img->x + 1] == 'P')
		ft_free_all(img, 1);
	if (img->map_s->map[img->y][img->x] == 'R'
		&& img->map_s->map[img->y][img->x + 1] == '0')
	{
		img->map_s->map[img->y][img->x + 1] = 'R';
		img->map_s->map[img->y][img->x] = '0';
	}
	else
		img->map_s->map[img->y][img->x] = 'L';
}

void	ft_enemy_left(t_data *img)
{
	if (img->map_s->map[img->y][img->x] == 'L'
		&& img->map_s->map[img->y][img->x - 1] == 'P')
		ft_free_all(img, 1);
	if (img->map_s->map[img->y][img->x] == 'L'
		&& img->map_s->map[img->y][img->x - 1] == '0')
	{
		img->map_s->map[img->y][img->x - 1] = 'L';
		img->map_s->map[img->y][img->x] = '0';
	}
	else
		img->map_s->map[img->y][img->x] = 'R';
}

void	ft_enemy(t_data *img)
{
	static int	i;

	if (!i)
		i = 0;
	if (i >= 8)
	{
		i = 0;
		if (img->map_s->map[img->y][img->x] == 'L')
			ft_enemy_left(img);
		if (img->map_s->map[img->y][img->x] == 'R')
			ft_enemy_right(img);
	}
	i++;
	return ;
}
