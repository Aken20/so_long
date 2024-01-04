/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:18:21 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/04 20:02:36 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_render(t_data *img)
{
	mlx_clear_window(img->mlx, img->win);
	while (img->y < img->map_s->y)
	{
		while (img->x < img->map_s->x)
		{
			if (img->map_s->map[img->y][img->x] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->img_s->wall,
					(img->x * img->size), (img->y * img->size));
			else if (img->map_s->map[img->y][img->x] == 'C')
				mlx_put_image_to_window(img->mlx, img->win,
					img->img_s->collectable, (img->x * img->size),
					(img->y * img->size));
			else if (img->map_s->map[img->y][img->x] == 'P')
			{
				img->map_s->p_x = img->x;
				img->map_s->p_y = img->y;
				mlx_put_image_to_window(img->mlx, img->win, img->img_s->player,
					(img->x * img->size), (img->y * img->size));
			}
			else if (img->map_s->map[img->y][img->x] == 'E')
			{
				if (ft_collectable_count(img->map_s->map))
					mlx_put_image_to_window(img->mlx, img->win,
						img->img_s->closed_door, (img->x * img->size),
						(img->y * img->size));
				else
					mlx_put_image_to_window(img->mlx, img->win,
						img->img_s->exit, (img->x * img->size),
						(img->y * img->size));
			}
			img->x++;
		}
		img->x = 0;
		img->y++;
	}
	img->y = 0;
	return (0);
}

void	ft_set_imgs(t_data *img)
{
	img->win = mlx_new_window(img->mlx, img->map_s->x * 60,
			img->map_s->y * 60, "Hello world!");
	img->img_s->wall = mlx_xpm_file_to_image(img->mlx, "wall.xpm",
			&img->size, &img->size);
	img->img_s->exit = mlx_xpm_file_to_image(img->mlx, "open_door.xpm",
			&img->size, &img->size);
	img->img_s->closed_door = mlx_xpm_file_to_image(img->mlx, "closed_door.xpm",
			&img->size, &img->size);
	img->img_s->collectable = mlx_xpm_file_to_image(img->mlx,
			"collectable2.xpm", &img->size, &img->size);
	img->img_s->player = mlx_xpm_file_to_image(img->mlx, "player1.xpm",
			&img->size, &img->size);
	img->x = 0;
	img->y = 0;
}

int	ft_quit_game(t_data *img)
{
	mlx_destroy_window(img->mlx, img->win);
	free(img);
	exit(0);
}

int	ft_hocks(int keycode, t_data *img)
{
	if (keycode == ESC)
		ft_quit_game(img);
	else if (keycode == W)
		ft_up(img);
	else if (keycode == A)
		ft_left(img);
	else if (keycode == S)
		ft_down(img);
	else if (keycode == D)
		ft_right(img);
	return (0);
}

int	main (int ac, char **av)
{
	int		i;
	t_data	*img;

	i = 0;
	if (ac == 2)
	{
		img = malloc(sizeof(t_data));
		img->size = 60;
		while (av[1][i])
			i++;
		i -= 4;
		if (ft_strncmp(av[1] + i, ".ber", 4))
			return (printf("wrong map"));
		i = 0;
		img = malloc(sizeof(t_data));
		img->map_s = malloc(sizeof(t_map));
		img->img_s = malloc(sizeof(t_imgs));
		img->map_s->map = ft_read_map(img->map_s->map, av[1]);
		img->map_s->x = (int)ft_strlen(img->map_s->map[0]);
		while (img->map_s->map[i])
			i++;
		img->map_s->y = i;
		// map_check(img->map_s->map);
		ft_check_map(img->map_s->map);
		img->mlx = mlx_init();
		ft_set_imgs(img);
		// ft_render(img);
		mlx_loop_hook(img->mlx, ft_render, img);
		mlx_hook(img->win, 2, 0, ft_hocks, img);
		mlx_loop(img->mlx);
		return (0);
	}
	else
		return (printf("there's no map"));
	return (0);
}
