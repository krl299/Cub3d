# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 09:18:17 by cmoran-l          #+#    #+#              #
#    Updated: 2023/09/12 15:18:41 by cmoran-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	./src/cub3d.c

OBJS		=	${SRCS:.c=.o}

LIBMLX		=	./libraries/MLX42	#Path of MLX42

MLXHEADER	=	./libraries/MLX42/include/MLX42

LIBFT		=	./libraries/libft	#Path of libft

HEADERS		=	-I ${MLXHEADER} -I ${LIBFT} 

LIBS		=	./libraries/MLX42/libmlx42.a	./libraries/libft/libft.a

GCC 		=	gcc -Wall -Werror -Wextra

NAME 		=	cub3d

RM 			= 	rm -rf

.c.o:
	@${GCC} -c $< ${HEADERS} -o ${<:.c=.o}

all:	lib	$(NAME)

lib:
	git submodule update --init
	make -C ${LIBFT} extra
	cd ./libraries/MLX42
	cmake -B build
	cmake --build build -j4

$(NAME): ${OBJS}
	${GCC} ${OBJS} ${LIBS} -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" ${HEADERS} -o ${NAME}

clean:
	${RM} ${OBJS}
	make -C ${LIBMLX} fclean
	make -C ${LIBFT} fclean

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re lib
