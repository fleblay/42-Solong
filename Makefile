SRCS = solong.c

OBJS = ${SRCS:.c=.o}

HEADER = ./includes/solong.h

INCLUDES = ./includes

NAME = solong

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	make -C ./minilibx/minilibx_opengl
	gcc -L ./minilibx/minilibx_opengl -lmlx -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}

%.o : %.c
	gcc -c $< -I ${INCLUDES} -o $@

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY:  clean fclean re
