# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mandriic <mandriic@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 09:18:17 by cmoran-l          #+#    #+#              #
#    Updated: 2023/09/28 13:05:36 by mandriic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



OBJS		=	${SRCS:.c=.o}

LIBMLX		=	libraries/MLX42

LIBFT		=	libraries/libft

HEADERS		=	-I ${LIBMLX}/include/MLX42 -I ${LIBFT} 

LIBS		=	${LIBMLX}/libmlx42.a	${LIBFT}/libft.a

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
	@${GCC} ${OBJS} ${LIBS} -lglfw $(GLFWLFLAG) ${HEADERS} -o ${NAME}

# clean:
# 	@${RM} ${OBJS}
# 	@make -C MLX42 fclean
# 	@make -C libft fclean

fclean: clean
	@${RM} ${NAME}

re: fclean all

linux: fclean lib ${OBJS}
	${GCC} ${OBJS} ${LIBS} -ldl -lglfw -pthread -lm ${HEADERS} -o ${NAME}

.PHONY: all clean fclean re lib
bonus: all

.PHONY: all clean fclean re NAME LIBFT lib bonus
