NAME = so_long

SRC_C =	main.c \
		check_map.c \
		check_map_helper.c \
		check_file_name.c \
		ft_split.c \
		get_next_line.c \
		get_next_line_utilits.c \
		ft_substr.c \
		init_map.c \
		check_path.c \
		get_locations.c \
		ft_itoa.c \
		ft_putnbr.c \
		enemy_movement.c \
		helper_utilits.c \
		init_helper1.c \
		init_helper2.c \
		init_helper3.c \
		init_helper4.c

COMPILER = cc

FLAGS = -Wall -Wextra -Werror

OBJC = $(SRC_C:.c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(COMPILER) $(FLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJC) -o $(NAME)

%.o : %.c so_long.h get_next_line.h
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJC) $(OBJ_BC)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all
