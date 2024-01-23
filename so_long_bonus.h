/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 10:16:33 by ahibrahi          #+#    #+#             */
/*   Updated: 2024/01/22 13:03:59 by ahibrahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"

typedef struct s_imgs
{
	void	*wall;
	void	*wall1;
	void	*player;
	void	*player_l;
	void	*player_r;
	void	*enemy_l;
	void	*enemy_r;
	void	*collectable;
	void	*floor;
	void	*fire1;
	void	*fire2;
	void	*fire3;
	void	*fire4;
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

int		ft_hocks(int keycode, t_data *img);
int		ft_collectable_count(char **map);
int		ft_check_map(t_data *img);
int		ft_valid_path(t_data *img, int x, int y);
void	ft_read_map(t_data *img, t_map *map, char *file);
int		ft_firstline(char *map);
int		ft_lastline(char *map, int len);
void	ft_up(t_map *map_s, t_data *img);
void	ft_down(t_map *map_s, t_data *img);
void	ft_left(t_map *map_s, t_data *img);
void	ft_right(t_map *map_s, t_data *img);
int		ft_quit_game(t_data *img);
int		ft_check_sides(char **map, int len);
int		ft_exits(char **map);
void	ft_handle(t_data *img, char c1, char c2, int i);
int		ft_is_valid(char **map, int y, int x);
void	*ft_allocate(t_data *img, char *file);
void	ft_free_all(t_data *img, int k);
void	ft_enemy_right(t_data *img);
void	ft_enemy_left(t_data *img);
void	ft_enemy(t_data *img);
void	ft_enemy_render(t_data *img);
void	ft_set_fire(t_data *img);
void	ft_render_fire(t_data *img);
int		ft_exit_count(char **map);
void	ft_check_read(t_data *img, char *s, int fd);

#endif