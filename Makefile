MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CFILES = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c sources/main.c sources/check_args.c sources/map.c \
sources/init_structs.c sources/check_map.c sources/free_functions.c sources/render.c
OBJS = ${CFILES:.c=.o}
RM = rm -rf
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
NAME = so_long
PRINTFA = ./ft_printf/libftprintf.a
PRINTFD = ./ft_printf
BONUSFILES = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c bonus/check_args_bonus.c bonus/check_map_bonus.c \
bonus/free_functions_bonus.c bonus/init_structs_bonus.c bonus/main_bonus.c bonus/map_bonus.c bonus/render_bonus.c bonus/move_jelly.c
OBJSBONUS = ${BONUSFILES:.c=.o}
NAMEBONUS = so_long_bonus

all: $(NAME)

$(NAME): $(OBJS) $(PRINTFA)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTFA) $(MLXFLAGS) -o $(NAME)

bonus: $(NAMEBONUS)

$(NAMEBONUS): $(PRINTFA) $(OBJSBONUS) 
	$(CC) $(CFLAGS) $(OBJSBONUS) $(PRINTFA) $(MLXFLAGS) -o $(NAMEBONUS)

$(PRINTFA): $(PRINTFD)
	make -C $(PRINTFD)

clean:
	$(RM) $(OBJS) $(OBJSBONUS)
	make clean -C $(PRINTFD)

fclean: clean
	$(RM) $(NAME) $(NAMEBONUS)
	make fclean -C $(PRINTFD)

re: fclean all
