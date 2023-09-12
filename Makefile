# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 09:18:17 by cmoran-l          #+#    #+#              #
#    Updated: 2023/09/12 09:37:30 by cmoran-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	

OBJS		=	${SRCS:.c=.o}

LIBMLX		=	#Path of MLX42

LIBFT		=	#Path of Libft

HEADERS		=	-I ${LIBMLX}/include/MLX42 -I ${LIBFT} 

LIBS		=	${LIBMLX}/libmlx42.a	${LIBFT}/libft.a

GCC 		=	gcc -Wall -Werror -Wextra

NAME 		=	cub3d

RM 			= 	rm -rf

.c.o:
	@${GCC} -c $< ${HEADERS} -o ${<:.c=.o}

all:	lib	$(NAME)

lib:
#	@git submodule update --init
#	@make -C libft extra
#	@make -C MLX42

$(NAME): ${OBJS}
	@${GCC} ${OBJS} ${LIBS} -lglfw -L "/Users/$USER/.brew/opt/glfw/lib/" ${HEADERS} -o ${NAME}

clean:
	@${RM} ${OBJS}
#	@make -C MLX42 fclean
#	@make -C libft fclean

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re lib
