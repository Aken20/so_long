#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"
#include<stdio.h>
#define ESC = 53
# define P player
# define E exit
# define C collectible

typedef struct	hashim_data {
	void	*img;
    char	**map;
	int		x;
	int		y;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
}	        t_map;


typedef struct	s_data {
	t_map	*map_s;
	void	*img;
	void	*win;
	void	*mlx;
	int		x;
	int		y;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
}	        t_data;
