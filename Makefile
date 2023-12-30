NAME = SO_SO_LONG
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar -rcs
RM = rm -f

FILES = so_long
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


all: $(PRINTF) $(GNL)
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) $(GNL) -o $(FILES)

clean:
	$(RM) $(FILES)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re