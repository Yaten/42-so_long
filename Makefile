# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 16:11:34 by prafael-          #+#    #+#              #
#    Updated: 2021/12/02 18:01:38 by prafael-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CFLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx/libmlx_Linux.a

SRC = 	so_long.c			\
		error.c				\
		start_game.c		\
		utils.c				\
		move.c				\
		verify_map.c		\
		hooks.c				\
		print_map.c			\
		print_map_utils.c	\

SRC_BONUS	= 	so_long_bonus.c			\
				error_bonus.c			\
				start_game_bonus.c		\
				utils_bonus.c			\
				move_bonus.c			\
				verify_map_bonus.c		\
				hooks_bonus.c			\
				print_map_bonus.c		\
				print_map_utils_bonus.c	\

OBJ = $(SRC:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)
	$(CC) $(addprefix ./src/,$(SRC)) $(CFLAGS) -I . -g3 -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	make others -C ./libft

$(MINILIBX):
	cd ./minilibx && ./configure

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(MINILIBX)
	$(CC) $(addprefix ./src_bonus/,$(SRC_BONUS)) $(CFLAGS) -I . -g3 -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz -o $(NAME_BONUS)

clean:
	rm -f $(LIBFT_OBJS) $(NAME) $(NAME_BONUS)
	make clean -C ./libft

fclean:
	make fclean -C ./libft
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

teste: all
	./$(NAME) "./assets/maps/map_3.ber"

testebonus: bonus
	./$(NAME_BONUS) "./assets/maps/map_3.ber"

valgrind: all
	valgrind -s --show-leak-kinds=all --track-origins=yes  --leak-check=full ./$(NAME) "./assets/maps/map_3.ber"

valgrindbonus: bonus
	valgrind -s --show-leak-kinds=all --track-origins=yes  --leak-check=full ./$(NAME_BONUS) "./assets/maps/map_3.ber"

.PHONY: all bonus clean fclean re teste testebonus valgrind valgrindbonus