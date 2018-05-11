#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akryvenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/13 11:21:19 by akryvenk          #+#    #+#              #
#    Updated: 2016/09/15 19:33:49 by akryvenk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d
NAME_L = LIBFT
NAME_H =  RTv1.h
LIB = ./libft/libft.a
MLX = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
FILE_SRCS = main.c \
w3d_contr_win.c \
w3d_draw_win.c \
w3d_contr_key.c  \
w3d_calc_func.c \
w3d_contr_mouse.c \
w3d_read_file.c 


FILE_O = $(FILE_SRCS:.c=.o)

OFLAGS	= -Wall -Wextra -Werror -c

.PHONY: all clean fclean re

OBJ = $(SRC:.c=.o)

all:  $(NAME_L) $(NAME_MLX) $(NAME)

$(NAME_L): $(FILE_SRCS:.libft/*.c=.libft/*.o)
	@make -C ./libft/

$(NAME_MLX):$(FILE_SRCS:.minilibx_macos/*.c=.minilibx_macos/*.o)
	@make -C ./minilibx_macos/

$(NAME): $(FILE_O)

	@gcc -O3 $(OFLAGS) $(FILE_SRCS)
	@gcc -o $(NAME) $(FILE_O) -I./minilibx_macos/ -I./libft/ $(LIB) $(MLX)

clean:
	@/bin/rm -f $(FILE_O)

fclean: clean
	@/bin/rm -f $(NAME)

cleanlib:
	@make clean -C libft/
	@make clean -C minilibx_macos/

fcleanlib: cleanlib
	@make fclean -C libft/
	@make fclean -C minilibx_macos/

re: all

norm:	@norminette *.c *.h
