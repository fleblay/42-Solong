SRCS = solong.c animate.c mlx.c events.c map.c

OBJS = ${SRCS:.c=.o}

HEADER = ./includes/solong.h

INCLUDES = -I ./includes

NAME = so_long

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	make -C ./minilibx/minilibx_opengl
	make -C ./libft
	gcc -Wall -Wextra -Werror -L ./minilibx/minilibx_opengl -lmlx -L ./libft -lft -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}

%.o : %.c ${HEADER}
	gcc -Wall -Wextra -Werror -c $< ${INCLUDES} -o $@

clean :
	rm -rf ${OBJS}
	make clean -C ./minilibx/minilibx_opengl
	make clean -C ./libft

fclean : clean
	rm -rf ${NAME}
	make clean -C ./minilibx/minilibx_opengl
	make fclean -C ./libft

re : fclean all

.PHONY:  clean fclean re
