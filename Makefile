# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmiftah <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 22:46:35 by tmiftah           #+#    #+#              #
#    Updated: 2023/01/04 22:46:40 by tmiftah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	mandatory/get_next_line.c \
		mandatory/get_next_line_utils.c \
		mandatory/lib.c \
		mandatory/so_long.c \
		mandatory/map_conf.c \
		mandatory/map_valid.c \
		mandatory/backtracking.c \
		mandatory/ft_printf.c \
		mandatory/print_map.c \
		mandatory/movements.c

SRC_B = bonus/get_next_line.c \
		bonus/get_next_line_utils.c \
		bonus/lib_bonus.c \
		bonus/so_long_bonus.c \
		bonus/map_conf_bonus.c \
		bonus/map_valid_bonus.c \
		bonus/backtracking_bonus.c \
		bonus/ft_printf_bonus.c \
		bonus/print_map_bonus.c \
		bonus/movements_bonus.c \
		bonus/ft_itoa.c \
		bonus/enemy.c

HEADER = so_long.h

NAME = so_long

BONUS = so_long_bonus

all = $(NAME)

CC = cc

CFALGS =  -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit 

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(SRC) $(HEADER)
	$(CC) $(CFALGS) $(SRC) -o $(NAME)

$(BONUS) : $(SRC_B) $(HEADER)
	$(CC) $(CFALGS) $(SRC_B) -o $(BONUS)

clean :
	@rm -rf $(NAME) $(BONUS)

fclean : clean

re : fclean all