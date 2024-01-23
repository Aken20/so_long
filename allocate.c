/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:30:26 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 14:50:20 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all(t_data *img, int k)
{
	int	i;

	i = 0;
	while (img->map_s->map[i] && &img->map_s->map[i] != NULL)
		free(img->map_s->map[i++]);
	i = 0;
	if (k == 1)
	{
		while (img->map_tmp->map[i] && img->map_tmp->map[i] != NULL)
			free(img->map_tmp->map[i++]);
		if (img->map_tmp->map)
			free(img->map_tmp->map);
	}
	if (img->map_s->map)
		free(img->map_s->map);
	if (img->map_s)
		free(img->map_s);
	if (img->map_tmp)
		free(img->map_tmp);
	if (img->img_s)
		free(img->img_s);
	if (img)
		free(img);
	exit (0);
}

int	ft_exit_count(char **map)
{
	int	exit;
	int	y;
	int	x;

	exit = 0;
	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				exit++;
			x++;
		}
		x = 0;
		y++;
	}
	return (exit);
}

void	ft_check_read(t_data *img, char *s, int fd)
{
	if (s)
	{
		while (s)
		{
			free(s);
			s = get_next_line(fd);
		}
		ft_printf("your map is not valid\n");
		ft_free_all(img, 0);
	}
}

void	*ft_allocate(t_data *img, char *file)
{
	int	i;

	i = 0;
	img->map_s = malloc(sizeof(t_map));
	if (!img->map_s)
		ft_free_all(img, 0);
	img->map_tmp = malloc(sizeof(t_map));
	img->img_s = malloc(sizeof(t_imgs));
	ft_read_map(img, img->map_s, file);
	if (!img->map_s || !img->map_tmp || !img->img_s)
		ft_free_all(img, 0);
	img->map_s->x = (int)ft_strlen(img->map_s->map[0]);
	while (img->map_s->map[i])
		i++;
	img->map_s->y = i;
	i = 0;
	ft_read_map(img, img->map_tmp, file);
	if (!ft_check_map(img))
		ft_free_all(img, 0);
	else if (!ft_valid_path(img, 0, 0))
	{
		ft_printf("ther's no valid path");
		ft_free_all(img, 1);
	}
	return (img);
}
