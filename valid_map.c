/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:38:14 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/08 14:02:02 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit_game(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	free(img);
	exit(0);
}

static	void ft_player(t_data *img)
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

// int		ft_valid_path(t_data *img, int x, int y)
// {
// 	int i;

// 	i = 0;
// 	if (x == 0 && y == 0)
// 	{
// 		ft_player(img);
// 		x = img->map_tmp->p_x;
// 		y = img->map_tmp->p_y;
// 	}
//     if (img->map_tmp->map[y][x] != '1')
// 	{
// 		// img->map_tmp->map[y][x] = '1';
// 		if (img->map_tmp->map[y - 1][x] == 'C' || img->map_tmp->map[y - 1][x] == '0')
// 		{
// 			img->map_tmp->map[y][x] = '1';
// 			ft_valid_path (img, x, y - 1);
// 		}
// 		if (img->map_tmp->map[y + 1][x] == 'C' || img->map_tmp->map[y + 1][x] == '0')
// 		{
// 			img->map_tmp->map[y][x] = '1';
// 			ft_valid_path (img, x, y + 1);
// 		}
// 		if (img->map_tmp->map[y][x - 1] == 'C' || img->map_tmp->map[y][x - 1] == '0')
// 		{
// 			img->map_tmp->map[y][x] = '1';
// 			ft_valid_path (img, x - 1, y);
// 		}
// 		if (img->map_tmp->map[y][x + 1] == 'C' || img->map_tmp->map[y][x + 1] == '0')
// 		{
// 			img->map_tmp->map[y][x] = '1';
// 			ft_valid_path (img, x + 1, y);
// 		}
// 		if (ft_collectable_count(img->map_tmp->map) == 0)
// 		{
// 			printf("x = %i   y = %i    C =  %d\n", x, y, ft_collectable_count(img->map_tmp->map));
// 			return (1);
// 		}
// 	}
// 	printf("x = %i   y = %i    C =  %d\n", x, y, ft_collectable_count(img->map_tmp->map));
// 	while (img->map_tmp->map[i])
// 		printf("%s\n", img->map_tmp->map[i++]);
// 	if (ft_collectable_count(img->map_tmp->map) == 0)
// 		return (1);
// 	else
// 		exit (ft_putstr("not a valid map\n"));
// }

int ft_valid_path(t_data *img, int x, int y)
{
	if (x == 0 && y == 0)
	{
		ft_player(img);
		x = img->map_tmp->p_x;
		y = img->map_tmp->p_y;
		img->map_tmp->p_s = 0;
	}
    if (img->map_tmp->map[y][x] == 'E' && !(ft_collectable_count(img->map_tmp->map)))
	{
        img->map_tmp->p_s = 1;
        return 1;
    }
    if (img->map_tmp->map[y][x] != '1' && img->map_tmp->map[y][x] != 'E')
    {
        img->map_tmp->map[y][x] = '1';
		if (y > 0)
        	ft_valid_path(img, x, y - 1);
		// if (img->map_tmp->map[y - 1][x] == 'E' && !(ft_collectable_count(img->map_tmp->map)))
		// 	img->map_tmp->p_s = 1;
		if (y < img->map_s->y)
        	ft_valid_path(img, x, y + 1);
		// if (img->map_tmp->map[y + 1][x] == 'E' && !(ft_collectable_count(img->map_tmp->map)))
		// 	img->map_tmp->p_s = 1;
		if (x > 0)
        	ft_valid_path(img, x - 1, y);
		// if (img->map_tmp->map[y][x - 1] == 'E' && !(ft_collectable_count(img->map_tmp->map)))
		// 	img->map_tmp->p_s = 1;
        if (x < img->map_s->x)
			ft_valid_path(img, x + 1, y);
		// if (img->map_tmp->map[y][x + 1] == 'E' && !(ft_collectable_count(img->map_tmp->map)))
		// 	img->map_tmp->p_s = 1;
    }
	// if (!(ft_collectable_count(img->map_tmp->map)))
	// 	img->map_tmp->map = ft_read_map(img->map_tmp->map, "map.ber");
	printf("x = %i   y = %i    C =  %d    ret = %d\n", x, y, ft_collectable_count(img->map_tmp->map), img->map_tmp->p_s);
	// while (img->map_tmp->map[i])
	// 	printf("%s\n", img->map_tmp->map[i++]);
	return (img->map_tmp->p_s);
}