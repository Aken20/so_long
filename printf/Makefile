# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahibrahi <ahibrahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 23:37:36 by ahibrahi          #+#    #+#              #
#    Updated: 2023/09/15 03:02:12 by ahibrahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

FILES = ft_putchar ft_putstr ft_putnbr ft_printf ft_u ft_itoa ft_p ft_hex ft_hexb \


SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re