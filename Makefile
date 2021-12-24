SRCS = solong.c animate.c animate2.c mlx.c mlx2.c events.c events2.c \
map.c check_tiles.c check_tiles2.c  mv_hero.c

OBJS = ${SRCS:.c=.o}

HEADER = ./includes/solong.h

INCLUDES = -I ./includes

NAME = so_long

#CC = /usr/bin/gcc
#CC = /opt/homebrew/bin/gcc-11
CC = /opt/homebrew/Cellar/llvm/13.0.0_2/bin/clang
#CC = /usr/bin/clang
#CC = /opt/homebrew/opt/llvm@13/bin/clang

#CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -L /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/lib/

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	make -C ./minilibx/minilibx_opengl
	make -C ./libft
	${CC} ${CFLAGS} -L ./minilibx/minilibx_opengl -lmlx -L ./libft -lft -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< ${INCLUDES} -o $@

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

#Compiler avec les flags et run avec
#ASAN_OPTIONS=detect_leaks=1 ./a.out par ex
