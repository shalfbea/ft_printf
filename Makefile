NAME := libftprintf.a

HEADER := include/ft_printf.h

CC := clang

TestingFlags := -fsanitize=address -g3

FLAGS := -Wall -Werror -Wextra -I./include

SRC_LIBFT_FILES = ft_strlen.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_strncmp.c ft_strlcat.c ft_strnstr.c\
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_bzero.c ft_atoi.c\
			ft_memset.c	ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
			ft_calloc.c ft_strdup.c ft_striteri.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c

SRC_FILES = building_list/data_to_list.c building_list/list_utils.c \
			building_list/converting.c building_list/itoa_base.c\
			ft_printf_and_result/ft_printf.c ft_printf_and_result/resulting.c \
			parsing/parse_args.c parsing/parse_flags.c parsing/parse_precision.c \
			parsing/parse_width.c parsing/parsing.c

OBJ = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ_LIBFT = $(addprefix libft/,$(patsubst %.c, %.o, $(SRC_LIBFT_FILES)))
RM := rm -rf

all: $(NAME) $(OBJ) $(OBJ_LIBFT) $(HEADER)

$(NAME) : $(OBJ) $(OBJ_LIBFT)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

testing : test

test : $(NAME) test_main.c
	$(CC) $(FLAGS) test_main.c $(NAME) -o test

all_bonus :
	ar rcs $(NAME) $?

clean:
	$(RM) $(OBJ) $(OBJ_LIBFT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re norm bonus
