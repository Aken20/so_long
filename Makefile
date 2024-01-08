NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
AR = ar -rcs
RM = rm -f

FILES = map so_long readmap movment valid_map
PFILES = ft_putchar ft_putstr ft_putnbr ft_printf ft_u ft_itoa ft_p ft_hex ft_hexb \

SRCS = $(addsuffix .c, $(FILES))
PSRCS = $(addsuffix .c, $(PFILES))
PSRCS1 = $(addprefix printf/, $(PSRCS))

OBJS = $(addsuffix .o, $(FILES))
POBJS = $(addsuffix .o, $(PFILES)) 
POBJS1 = $(addprefix printf/, $(POBJS))

GNL = get_next_line/GNL.a
PRINTF = printf/printf.a
LIBFT = libft/libft.a
MLX = mlx/libmlx.a

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(PRINTF) $(GNL) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)

$(MAKE): make re

$(GNL):
	make -C get_next_line
$(PRINTF):
	make -C printf
$(LIBFT):
	make -C libft
$(MLX):
	make -C mlx

clean:
	$(RM) $(FILES)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re