/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:18:21 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 14:31:54 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_set_render(t_data *img)
{
	if (img->map_s->map[img->y][img->x] == 'E'
			|| img->map_s->map[img->y][img->x] == 'A')
	{
		if (ft_collectable_count(img->map_s->map))
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->closed_door,
				(img->x * img->size), (img->y * img->size));
		else
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->exit,
				(img->x * img->size), (img->y * img->size));
	}
	if (img->map_s->map[img->y][img->x] == 'P'
		|| img->map_s->map[img->y][img->x] == 'A')
	{
		img->map_s->p_x = img->x;
		img->map_s->p_y = img->y;
		if (img->map_s->p_s == 2)
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->player_l,
				(img->x * img->size), (img->y * img->size));
		else if (img->map_s->p_s == 1)
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->player_r,
				(img->x * img->size), (img->y * img->size));
		else
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->player,
				(img->x * img->size), (img->y * img->size));
	}
}

void	ft_enemy_render(t_data *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img_s->floor,
		(img->x * img->size), (img->y * img->size));
	if (img->map_s->map[img->y][img->x] == '1' && ((img->x != 0 && img->y != 0)
		&& (img->x != img->map_s->x - 1 && img->y != img->map_s->y - 1)))
		mlx_put_image_to_window(img->mlx, img->win, img->img_s->wall1,
			(img->x * img->size), (img->y * img->size));
	else if (img->map_s->map[img->y][img->x] == 'C')
		mlx_put_image_to_window(img->mlx, img->win,
			img->img_s->collectable, (img->x * img->size),
			(img->y * img->size));
	if (img->map_s->map[img->y][img->x] == 'L')
	{
		mlx_put_image_to_window(img->mlx, img->win,
			img->img_s->enemy_l, (img->x * img->size),
			(img->y * img->size));
		ft_enemy(img);
	}
	else if (img->map_s->map[img->y][img->x] == 'R')
	{
		mlx_put_image_to_window(img->mlx, img->win,
			img->img_s->enemy_r, (img->x * img->size),
			(img->y * img->size));
		ft_enemy(img);
	}
}

int	ft_render(t_data *img)
{
	mlx_clear_window(img->mlx, img->win);
	while (img->y < img->map_s->y)
	{
		while (img->x < img->map_s->x)
		{
			ft_enemy_render(img);
			if (img->map_s->map[img->y][img->x] == '1'
				&& (img->x == 0 || img->y == 0 ||
				img->x == img->map_s->x - 1 || img->y == img->map_s->y - 1))
				mlx_put_image_to_window(img->mlx, img->win, img->img_s->wall,
					(img->x * img->size), (img->y * img->size));
			ft_set_render(img);
			ft_render_fire(img);
			img->x++;
		}
		img->x = 0;
		img->y++;
	}
	img->y = 0;
	mlx_string_put(img->mlx, img->win, 5,
		(img->map_s->y * img->size) + 10, 0xff00, "moves:");
	mlx_string_put(img->mlx, img->win, 50, img->map_s->y
		* img->size + 10, 0xff00, ft_itoa(img->moves));
	mlx_do_sync(img->mlx);
	return (0);
}

void	ft_set_imgs(t_data *img)
{
	img->win = mlx_new_window(img->mlx, img->map_s->x * 60,
			(img->map_s->y * 60) + 15, "so_long_bonus");
	img->img_s->exit = mlx_xpm_file_to_image(img->mlx, "texture/open_door.xpm",
			&img->size, &img->size);
	img->img_s->closed_door = mlx_xpm_file_to_image(img->mlx,
			"texture/closed_door.xpm", &img->size, &img->size);
	img->img_s->floor = mlx_xpm_file_to_image(img->mlx,
			"texture/floor.xpm", &img->size, &img->size);
	img->img_s->collectable = mlx_xpm_file_to_image(img->mlx,
			"texture/collectable2.xpm", &img->size, &img->size);
	img->img_s->player = mlx_xpm_file_to_image(img->mlx, "texture/player.xpm",
			&img->size, &img->size);
	img->img_s->player_r = mlx_xpm_file_to_image(img->mlx,
			"texture/player_r.xpm", &img->size, &img->size);
	img->img_s->player_l = mlx_xpm_file_to_image(img->mlx,
			"texture/player_l.xpm", &img->size, &img->size);
	img->img_s->enemy_r = mlx_xpm_file_to_image(img->mlx,
			"texture/skiliton_r.xpm", &img->size, &img->size);
	img->img_s->enemy_l = mlx_xpm_file_to_image(img->mlx,
			"texture/skiliton_l.xpm", &img->size, &img->size);
	ft_set_fire(img);
	img->x = 0;
	img->y = 0;
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
			return (printf("wrong map"));
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
