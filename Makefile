SRCS = solong.c animate.c mlx.c events.c

OBJS = ${SRCS:.c=.o}

HEADER = ./includes/solong.h

INCLUDES = ./includes

NAME = so_long

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	make -C ./minilibx/minilibx_opengl
	gcc -Wall -Wextra -Werror -L ./minilibx/minilibx_opengl -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}

%.o : %.c
	gcc -Wall -Wextra -Werror -c $< -I ${INCLUDES} -o $@

clean :
	rm -rf ${OBJS}
	make clean -C ./minilibx/minilibx_opengl

fclean : clean
	rm -rf ${NAME}
	make clean -C ./minilibx/minilibx_opengl

re : fclean all

.PHONY:  clean fclean re
