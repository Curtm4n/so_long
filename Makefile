# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 20:09:51 by cdapurif          #+#    #+#              #
#    Updated: 2021/08/21 20:28:51 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	so_long.c \
		parsing.c \
		parsing2.c \
		parsing3.c \
		get_next_line.c \
		get_next_line_utils.c \
		get_next_line_utils2.c \
		display.c \
		game.c \
		event.c \
		texture.c

SRCS_PATH = srcs/

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

CC = clang

CFLAGS = -Wall -Wextra -Werror

FT = -L srcs/libft -lft

MLX = -L srcs/mlx -lmlx -lX11 -lXext

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C srcs/libft/ bonus
	make -C srcs/mlx/
	echo "\033[36;1mCreation:\033[0m \033[35;4m$(NAME)\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT) $(MLX)

clean:
	$(RM) $(OBJS)
	make -C srcs/libft/ clean
	make -C srcs/mlx/ clean

fclean: clean
	$(RM) $(NAME)
	make -C srcs/libft/ fclean

re: fclean all

.PHONY: all clean fclean re
