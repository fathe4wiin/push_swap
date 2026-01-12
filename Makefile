NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Wno-unused-result -I.

SRC_MOVES	= moves/move_push.c \
			  moves/move_rev_rotate.c \
			  moves/move_rotate.c \
			  moves/move_swap.c

SRC_PARSING	= parsing/error.c \
			  parsing/parse_checks.c \
			  parsing/parsing.c \
			  parsing/print_opt.c

SRC_SORTING	= sorting/simple_sort.c \
			  sorting/sorting.c \
			  sorting/utils_sorting_1.c \
			  sorting/utils_sorting_2.c

SRC_UTILS	= utils/ft_atol.c \
			  utils/ft_split.c \
			  utils/ft_utils_1.c \
			  utils/ft_utils_2.c \
			  utils/ft_lists_1.c \
			  utils/ft_lists_2.c

COMMON_SRC	= $(SRC_MOVES) $(SRC_PARSING) $(SRC_SORTING) $(SRC_UTILS)

SRC			= $(COMMON_SRC) main.c

SRC_BONUS	= $(COMMON_SRC) \
			  __main_bonus.c \
			  bonus/utils_bonus.c \
			  gnl/get_next_line.c \
			  gnl/get_next_line_utils.c

OBJ			= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)
NAME_BONUS	= checker

all: $(NAME)

bonus: $(NAME_BONUS)

check: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus check

.SECONDARY: $(OBJ) $(OBJ_BONUS)
