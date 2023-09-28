USER = $(shell whoami)
UNAME_S := $(shell uname -s)
ifeq ($(USER), $(filter mandriic,cmoran-l))
	GLFWLFLAG = -L/Users/$(USER)/.brew/opt/glfw/lib/
	# R42IFLAG = -I/Users/$(USER)/.brew/opt/readline/include
endif
ifeq ($(USER), sirius)
ifeq ($(UNAME_S),Darwin)
	GLFWLFLAG = -L/opt/homebrew/opt/glfw/lib/
	# R42IFLAG = -I/opt/homebrew/opt/readline/include
endif
endif
# ifeq ($(UNAME_S),Linux)
# 	R42LFLAG = -L/usr/share/readline 
# 	R42IFLAG = -I/usr/include/readline
# endif

SRCS		=	src/cub3d.c src/hooks.c src/utils.c  

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

bonus: all

.PHONY: all clean fclean re NAME LIBFT lib bonus
