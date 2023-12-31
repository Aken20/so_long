/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:16:33 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/08 14:29:23 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"
#include <stdio.h>

typedef struct s_imgs
{
	int		moves;
	void	*wall;
	void	*player;
	void	*player_l;
	void	*player_r;
	void	*collectable;
	void	*exit;
	void	*closed_door;
}				t_imgs;

typedef struct s_map
{
	char	**map;
	int		p_x;
	int		p_y;
	int		p_s;
	int		x;
	int		y;
}				t_map;

typedef struct s_data
{
	t_map	*map_s;
	t_map	*map_tmp;
	t_imgs	*img_s;
	void	*win;
	void	*mlx;
	int		size;
	int		moves;
	int		x;
	int		y;
}				t_data;

int		ft_collectable_count(char **map);
int		ft_check_map(t_data *img);
int		ft_valid_path(t_data *img, int x, int y);
char	**ft_read_map(char **map, char *file);
int		ft_firstline(char **map);
int		ft_lastline(char *map, int len);
void	ft_up(t_map *map_s, t_data *img);
void	ft_down(t_map *map_s, t_data *img);
void	ft_left(t_map *map_s, t_data *img);
void	ft_right(t_map *map_s, t_data *img);
int		ft_quit_game(t_data *img);
int		ft_check_sides(char **map, int len);
int		ft_exits(char **map);
