NAME = so_long
SRCS = main.c window.c image.c hooks.c map.c mapchecker.c mapchecker2.c map_generator.c map_generator2.c bonus.c bonus2.c get_next_line.c get_next_line_utils.c ft_itoa.c ft_strdup.c
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
CFLAGS2 = -lXext -lX11 -lm -lz
LIB = minilibx-linux/libmlx.a

all: mlx $(NAME)

bonus : all

%.o: %.c
	$(CC) -c $(CFLAGS) $(SRCS) $(CFLAGS2) $?
mlx:
	cd minilibx-linux && $(MAKE) -s
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(CFLAGS2) -o $(NAME)
clean: mlx_clean
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
mlx_clean:
	cd minilibx-linux/ && $(MAKE) clean
.PHONY: all mlx clean fclean re mlx_clean .c.o