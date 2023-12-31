#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"

#define ESC = 53
# define P player
# define E exit
# define C collectible


typedef struct	s_data {
	void	*img;
	void	*win;
	void	*mlx;
	int		x;
	int		y;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
}	        t_data;
