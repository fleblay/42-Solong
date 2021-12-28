SRCS_FILES = solong.c animate.c animate2.c mlx.c mlx2.c events.c events2.c \
map.c check_tiles.c check_tiles2.c mv_hero.c img_load.c errors.c

SRCS_DIR = ./srcs/

SRCS= ${addprefix ${SRCS_DIR}, ${SRCS_FILES}}

OBJS = ${SRCS:.c=.o}

HEADER = ./includes/solong.h

INCLUDES = -I ./includes

NAME = so_long


# TEST FLAGS
#CC = /opt/homebrew/bin/gcc-11
#CC = /opt/homebrew/opt/llvm@13/bin/clang (SAME AS M1 FLAG?)

#NORMAL FLAG FOR 42 MAC
CC = gcc
#FLAG FOR MAC M1 AFTER CLEAN INSTAL LLVM
#CC = /opt/homebrew/Cellar/llvm/13.0.0_2/bin/clang

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

bonus : CFLAGS := ${CFLAGS} -D BONUS=1

all : ${NAME}

bonus : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	#make -C ./minilibx/minilibx_opengl
	make -C ./minilibx-linux
	make -C ./libft
	#${CC} ${CFLAGS} -L ./minilibx/minilibx_opengl -lmlx -L ./libft -lft -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}
	#${CC} ${CFLAGS} -L ./minilibx-linux -lmlx -L ./libft -lft -L /usr/X11/include/../lib -lXext -lX11 -lm -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}
	${CC} ${CFLAGS} -L ./minilibx-linux -lmlx -L ./libft -lft -L /usr/X11/include/../lib -lXext -lX11 -o ${NAME} ${OBJS}

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< ${INCLUDES} -o $@

clean :
	rm -rf ${OBJS}
	#make clean -C ./minilibx/minilibx_opengl
	make clean -C ./minilibx-linux
	make clean -C ./libft

fclean : 
	rm -rf ${OBJS}
	rm -rf ${NAME}
	#make clean -C ./minilibx/minilibx_opengl
	make clean -C ./minilibx-linux
	make fclean -C ./libft

re : fclean all

.PHONY:  clean fclean re all bonus

#Compiler avec les flags et run avec
#ASAN_OPTIONS=detect_leaks=1 ./a.out par ex
