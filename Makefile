CFILES = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c main.c check_input.c map.c \
init_structs.c check_map.c free_functions.c render.c
OBJS = ${CFILES:.c=.o}
RM = rm -rf
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
NAME = so_long
PRINTFA = ./ft_printf/libftprintf.a
PRINTFD = ./ft_printf

all: $(NAME)

$(NAME): $(OBJS) $(PRINTFA) 
	$(CC) $(CFLAGS) $(OBJS) $(PRINTFA) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(PRINTFA): $(PRINTFD)
	make -C $(PRINTFD)

clean:
	$(RM) $(OBJS)
	make clean -C $(PRINTFD)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(PRINTFD)

re: fclean all