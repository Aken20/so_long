/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fire_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 02:42:47 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 14:30:20 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_set_fire(t_data *img)
{
	img->moves = 0;
	img->img_s->wall = mlx_xpm_file_to_image(img->mlx, "texture/wall.xpm",
			&img->size, &img->size);
	img->img_s->wall1 = mlx_xpm_file_to_image(img->mlx, "texture/wall1.xpm",
			&img->size, &img->size);
	img->img_s->fire1 = mlx_xpm_file_to_image(img->mlx,
			"texture/fire1.xpm", &img->size, &img->size);
	img->img_s->fire2 = mlx_xpm_file_to_image(img->mlx,
			"texture/fire2.xpm", &img->size, &img->size);
	img->img_s->fire3 = mlx_xpm_file_to_image(img->mlx,
			"texture/fire3.xpm", &img->size, &img->size);
	img->img_s->fire4 = mlx_xpm_file_to_image(img->mlx,
			"texture/fire4.xpm", &img->size, &img->size);
	if (!img->img_s->fire4 || !img->img_s->fire3 || !img->img_s->fire2
		|| !img->img_s->fire1 || !img->img_s->wall || !img->img_s->wall1
		|| !img->img_s->floor || !img->img_s->closed_door
		|| !img->img_s->collectable || !img->img_s->player
		|| !img->img_s->player_r || !img->img_s->player_l
		|| !img->img_s->enemy_r || !img->img_s->enemy_l)
	{
		ft_printf("some files are missing\n");
		ft_quit_game(img);
	}
}

void	ft_render_fire(t_data *img)
{
	static int	i;

	if (!i)
		i = 0;
	if (img->map_s->map[img->y][img->x] == '1' &&
		(((img->y == 0 || img->y == img->map_s->y - 1) && (img->x % 2 == 0))
		|| ((img->y % 2 == 0) && (img->x == 0 || img->x == img->map_s->x - 1))))
	{
		if (i <= 250)
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->fire1,
				(img->x * img->size), (img->y * img->size));
		if (i <= 500)
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->fire2,
				(img->x * img->size), (img->y * img->size));
		if (i <= 750)
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->fire3,
				(img->x * img->size), (img->y * img->size));
		if (i <= 1000)
			mlx_put_image_to_window(img->mlx, img->win, img->img_s->fire4,
				(img->x * img->size), (img->y * img->size));
		else if (i >= 1000)
			i = 0;
		i++;
	}
}
