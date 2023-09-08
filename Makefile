SRCS		=	cub3d.c

OBJS		=	${SRCS:.c=.o}

LIBMLX		=	./MLX42

LIBFT		=	./libft

HEADERS		=	-I ${LIBMLX}/include/MLX42 -I ${LIBFT} 

LIBS		=	${LIBMLX}/libmlx42.a	${LIBFT}/libft.a

GCC = gcc #-Wall -Werror -Wextra

NAME = cub3d

RM = rm -rf

.c.o:
	@${GCC} -c $< ${HEADERS} -o ${<:.c=.o}

all:	$(NAME)

#lib:
#	@git submodule update --init
#	@make -C libft extra
#	@make -C MLX42

$(NAME): ${OBJS}
	@${GCC} ${OBJS} ${LIBS} -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" ${HEADERS} -o ${NAME}

# clean:
# 	@${RM} ${OBJS}
# 	@make -C MLX42 fclean
# 	@make -C libft fclean

fclean: clean
	@${RM} ${NAME}

re: fclean all

bonus: all

.PHONY: all clean fclean re NAME LIBFT lib bonus
