/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:18:21 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 14:32:09 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_render(t_data *img, int x, int y)
{
	if (img->map_s->map[y][x] == '1')
		mlx_put_image_to_window(img->mlx, img->win, img->img_s->wall,
			(x * img->size), (y * img->size));
	else if (img->map_s->map[y][x] == 'C')
		mlx_put_image_to_window(img->mlx, img->win,
			img->img_s->collectable, (x * img->size),
			(y * img->size));
	else if (img->map_s->map[y][x] == 'P'
			|| img->map_s->map[img->y][img->x] == 'A')
	{
		img->map_s->p_x = x;
		img->map_s->p_y = y;
		if (img->map_s->p_s == 2)
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->player_l,
				(x * img->size), (y * img->size));
		else if (img->map_s->p_s == 1)
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->player_r,
				(x * img->size), (y * img->size));
		else
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->player,
				(x * img->size), (y * img->size));
	}
}

int	ft_render(t_data *img)
{
	mlx_clear_window(img->mlx, img->win);
	while (img->y < img->map_s->y)
	{
		while (img->x < img->map_s->x)
		{
			if (img->map_s->map[img->y][img->x] == 'E'
					|| img->map_s->map[img->y][img->x] == 'A')
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
			ft_set_render(img, img->x, img->y);
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
	img->moves = 0;
	img->win = mlx_new_window(img->mlx, img->map_s->x * 60,
			img->map_s->y * 60, "Game");
	img->img_s->wall = mlx_xpm_file_to_image(img->mlx, "texture/wall.xpm",
			&img->size, &img->size);
	img->img_s->exit = mlx_xpm_file_to_image(img->mlx, "texture/open_door.xpm",
			&img->size, &img->size);
	img->img_s->closed_door = mlx_xpm_file_to_image(img->mlx,
			"texture/closed_door.xpm", &img->size, &img->size);
	img->img_s->collectable = mlx_xpm_file_to_image(img->mlx,
			"texture/collectable2.xpm", &img->size, &img->size);
	img->img_s->player = mlx_xpm_file_to_image(img->mlx, "texture/player.xpm",
			&img->size, &img->size);
	img->img_s->player_r = mlx_xpm_file_to_image(img->mlx,
			"texture/player_r.xpm", &img->size, &img->size);
	img->img_s->player_l = mlx_xpm_file_to_image(img->mlx,
			"texture/player_l.xpm", &img->size, &img->size);
	img->x = 0;
	img->y = 0;
}

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

int	main(int ac, char **av)
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
			return (ft_printf("wrong map"));
		img = ft_allocate(img, av[1]);
		img->mlx = mlx_init();
		ft_set_imgs(img);
		mlx_loop_hook(img->mlx, ft_render, img);
		mlx_hook(img->win, 2, 0, ft_hocks, img);
		mlx_hook(img->win, 17, 0, ft_quit_game, img);
		mlx_loop(img->mlx);
	}
	return (printf("there's no map"));
}
