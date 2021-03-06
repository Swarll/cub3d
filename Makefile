# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 11:18:53 by user42            #+#    #+#              #
#    Updated: 2020/10/27 12:12:21 by grigaux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_ROOT = ./libft
LIBFT = libft.a
LIB_GRAPH = -framework OpenGl -framework Appkit -L minilibx_opengl -lmlx

CC = gcc
CCFLAGS = -Wall -Werror -Wextra 
INCLAGS = -I$(LIBFT_ROOT) $(LIB_GRAPH) 
RM = rm -f
LIB = ar rcs

NAME = cub3d

SRC = main.c handle_line.c utils.c map_checker.c inits.c algo.c hooks.c \
	handle_text.c handle_sprites.c hooks_move.c draw.c handle_map.c bmp.c

OBJ = $(SRC:.c=.o)
	INCLUDE = cub3d.h 

all : libft_all $(NAME)

$(NAME) : $(OBJ)
	cp $(LIBFT_ROOT)/$(LIBFT) .
		$(CC) $(CCFLAGS) $(LIB_GRAPH) $(LIBFT_ROOT)/libft.a $(OBJ) -o $(NAME)

%.o: %.c
		$(CC) $(CCFLAGS) $(INCFLAGS) -c -o $@ $<
libft_all:
		$(MAKE) -C $(LIBFT_ROOT) all
libft_clean:
		$(MAKE) -C $(LIBFT_ROOT) clean
libft_fclean:
		$(MAKE) -C $(LIBFT_ROOT) fclean
clean: libft_clean
		$(RM) $(OBJ)

fclean: libft_fclean clean
		$(RM) $(NAME) $(LIBFT)

re: fclean all