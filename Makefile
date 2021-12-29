SRCS_FILES = solong.c animate.c animate2.c mlx.c mlx2.c events.c events2.c \
map.c check_tiles.c check_tiles2.c mv_hero.c img_load.c errors.c

SRCS_DIR = ./srcs/

SRCS= ${addprefix ${SRCS_DIR}, ${SRCS_FILES}}

OBJS = ${SRCS:.c=.o}

HEADER = ./includes/solong.h

INCLUDES = -I ./includes

MLX_DIR = ./minilibx-linux
MLX_OLDDIR = ./minilibx/minilibx_opengl

EXTERN_LIB = -L /usr/X11/include/../lib -lXext -lX11
EXTERN_OLDLIB = -framework OpenGL -framework AppKit

NAME = so_long

#NORMAL FLAG FOR 42 MAC
CC = gcc

#FLAG FOR MAC M1 AFTER CLEAN INSTAL LLVM
#CC = /opt/homebrew/Cellar/llvm/13.0.0_2/bin/clang

#CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

bonus : CFLAGS += -D NEWBONUS=1

ifeq (${MAKECMDGOALS}, old)
CFLAGS += -D OLD=1
MLX_DIR = ${MLX_OLDDIR}
EXTERNLIB = ${EXTERN_OLDLIB}
endif

oldbonus : CFLAGS += -D OLDBONUS=1
oldbonus : MLX_DIR = ${MLX_OLDDIR}
oldbonus : EXTERNLIB = ${EXTERN_OLDLIB}

all : ${NAME}
bonus : ${NAME}
#old : ${NAME}
oldbonus : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	make -C ${MLX_DIR}
	make -C ./libft
	${CC} ${CFLAGS} ${OBJS} -L ./libft -lft -L ${MLX_DIR} -lmlx ${EXTERN_LIB} -o ${NAME}

old : ${OBJS} ${HEADER}
	make -C ${MLX_DIR}
	make -C ./libft
	${CC} ${CFLAGS} -L ${MLX_DIR} -lmlx -L ./libft -lft -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}

oldbonus : ${OBJS} ${HEADER}
	make -C ${MLX_DIR}
	make -C ./libft
	${CC} ${CFLAGS} -L ${MLX_DIR} -lmlx -L ./libft -lft -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -c $< ${INCLUDES} -o $@

clean :
	rm -rf ${OBJS}
	make clean -C ./minilibx/minilibx_opengl
	make clean -C ./minilibx-linux
	make clean -C ./libft

fclean : clean
	rm -rf ${NAME}
	rm -rf ./libft/libft.a
	rm -rf ./minilibx/minilibx_opengl/libmlx.a
	rm -rf ./minilibx-linux/libmlx.a

re : fclean all

.PHONY:  clean fclean re all bonus old oldbonus oldclean oldfclean

#Compiler avec les flags et run avec
#ASAN_OPTIONS=detect_leaks=1 ./a.out par ex

#${CC} ${CFLAGS} -L ./minilibx-linux -lmlx -L ./libft -lft -L /usr/X11/include/../lib -lXext -lX11 -lm -framework OpenGL -framework AppKit -o ${NAME} ${OBJS}
