NAME := libftprintf.a

HEADER := include/ft_printf.h

CC := clang

TestingFlags := -fsanitize=address -g3

FLAGS := -Wall -Werror -Wextra -I./include

SRC_FILES = building_list/data_to_list.c building_list/list_utils.c \
			building_list/converting.c building_list/itoa_base.c\
			building_list/building.c building_list/element_modify.c\
			ft_printf.c \
			parsing/parse_flags_and_args.c parsing/parse_numeric.c \
			parsing/parsing.c \
			utils/string_utilities.c

OBJ = $(patsubst %.c, %.o, $(SRC_FILES))
RM := rm -rf

all: $(NAME) $(OBJ) $(HEADER)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

bonus : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

testing : test

test : $(NAME) test_main.c
	$(CC) $(FLAGS) test_main.c $(NAME) -o test

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: $(SRC_FILES)
	norminette $<

.PHONY: all clean fclean re norm bonus
