# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/13 20:09:51 by cdapurif          #+#    #+#              #
#    Updated: 2021/08/30 15:30:51 by cdapurif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

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

SRCS_BONUS =	so_long_bonus.c \
				parsing_bonus.c \
				parsing2_bonus.c \
				parsing3_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				get_next_line_utils2_bonus.c \
				display_bonus.c \
				game_bonus.c \
				event_bonus.c \
				texture_bonus.c

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

OBJS_BONUS = $(addprefix srcs_bonus/,$(SRCS_BONUS:.c=.o))

CC = clang

CFLAGS = -Wall -Wextra -Werror

FT = -L lib/libft -lft

MLX = -L lib/mlx -lmlx -lX11 -lXext

RM = rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	make -C lib/libft/ bonus
	make -C lib/mlx/
	echo "\033[36;1mCreation:\033[0m \033[35;4m$(NAME)\033[0m"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(FT) $(MLX)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C lib/libft/ bonus
	make -C lib/mlx/
	echo "\033[36;1mCreation:\033[0m \033[35;4m$(NAME_BONUS)\033[0m"
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(FT) $(MLX)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	make -C lib/libft/ clean
	make -C lib/mlx/ clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	make -C lib/libft/ fclean

re: fclean all

re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus
