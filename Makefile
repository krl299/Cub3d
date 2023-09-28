# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mandriic <mandriic@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 09:18:17 by cmoran-l          #+#    #+#              #
#    Updated: 2023/09/28 15:09:03 by mandriic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(USER), $(filter mandriic,cmoranl))
       GLFWLFLAG = L/Users/$(USER)/.brew/opt/glfw/lib/
       # R42IFLAG = I/Users/$(USER)/.brew/opt/readline/include
endif
ifeq ($(USER), sirius)
	GLFWLFLAG = -L/opt/homebrew/opt/glfw/lib/
endif
       # R42IFLAG = I/opt/homebrew/opt/readline/include

SRCS           =  ./libraries/libft/gnl/get_next_line.c ./libraries/libft/gnl/get_next_line_utils.c ./src/hooks.c ./src/utils.c ./src/parser/error_parser.c ./src/cub3d.c ./src/parser/parser.c ./src/parser/textures.c ./src/parser/init.c     ./src/parser/test.c     ./src/parser/color.c    ./src/parser/map.c

OBJS		=	${SRCS:.c=.o}

LIBMLX		=	./libraries/MLX42/

LIBFT		=	./libraries/libft/
# GNL		=	./libraries/libft/gnl
# PRF		=	./libraries/libft/printf

HEADERS		=	-I ${LIBMLX}/include/MLX42 -I ${LIBFT} -I ${GNL} -I ${PRF} 

LIBS		=	${LIBMLX}/libmlx42.a	${LIBFT}/libft.a $

GCC = gcc #-Wall -Werror -Wextra

NAME = cub3d

RM = rm -rf

.c.o:
	@${GCC} -c $< ${HEADERS} -o ${<:.c=.o}

all:	lib	$(NAME)

# lib:
# 	@git submodule update --init
# 	@make -C libft extra
# 	@make -C MLX42

$(NAME): ${OBJS}
	@${GCC} ${OBJS} ${LIBS} -lglfw ${GLFWLFLAG} ${HEADERS} -o ${NAME}


fclean: clean
	@${RM} ${NAME}

re: fclean all

# linux: fclean lib ${OBJS}
# 	${GCC} ${OBJS} ${LIBS} -ldl -lglfw -pthread -lm ${HEADERS} -o ${NAME}

.PHONY: all clean fclean re lib
bonus: all

.PHONY: all clean fclean re NAME LIBFT lib bonus
