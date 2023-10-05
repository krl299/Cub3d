# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mandriic <mandriic@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 09:18:17 by cmoran-l          #+#    #+#              #
#    Updated: 2023/09/30 11:49:02 by mandriic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER = $(shell whoami)
# ifeq ($(USER), $(filter mandriic,cmoranl))
       GLFWLFLAG = -L /Users/$(USER)/.brew/opt/glfw/lib/
       # R42IFLAG = I/Users/$(USER)/.brew/opt/readline/include
# endif
# ifeq ($(USER), sirius)
# 	GLFWLFLAG = -L /opt/homebrew/opt/glfw/lib/
# endif
       # R42IFLAG = I/opt/homebrew/opt/readline/include

SRCS           =   ./src/mini_map.c ./src/hooks.c ./src/utils.c ./src/parser/error_parser.c ./src/cub3d.c ./src/parser/parser.c ./src/parser/textures.c ./src/parser/init.c     ./src/parser/test.c     ./src/parser/color.c    ./src/parser/map.c

OBJS		=	${SRCS:.c=.o}

LIBMLX		=	./libraries/MLX42

MLXHEADER	=	./libraries/MLX42/include/MLX42

MLXBUILD	=	./libraries/MLX42/build

LIBFT		=	./libraries/libft

HEADERS		=	-I ${MLXHEADER} -I ${LIBFT} 

LIBS		=	./libraries/MLX42/build/libmlx42.a	./libraries/libft/libft.a

GCC = gcc #-Wall -Werror -Wextra

NAME = cub3d

RM = rm -rf

.c.o:
	@${GCC} -c $< ${HEADERS} -o ${<:.c=.o}

all:	lib	$(NAME)

lib:
	@git submodule update --init
	@make -C ${LIBFT} extra
	@cmake ${LIBMLX} -B ${MLXBUILD} && make -C ${MLXBUILD} -j4

$(NAME): ${OBJS}
	@${GCC} ${OBJS} ${LIBS} -lglfw ${GLFWLFLAG} ${HEADERS} -o ${NAME}

clean:
	@${RM} ${OBJS}
	@make -C ${LIBFT} fclean
	@rm -rf ./libraries/MLX42/build

fclean: clean
	@${RM} ${NAME}

re: fclean all

# linux: fclean lib ${OBJS}
# 	${GCC} ${OBJS} ${LIBS} -ldl -lglfw -pthread -lm ${HEADERS} -o ${NAME}

bonus: all

.PHONY: all clean fclean re NAME LIBFT lib bonus
