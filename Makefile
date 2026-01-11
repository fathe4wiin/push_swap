NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Wno-unused-result

COMMON_SRC	= error.c \
			  ft_atol.c \
			  ft_split.c \
			  ft_utils.c \
			  indexing.c \
			  lists.c \
			  move_push.c \
			  move_rev_rotate.c \
			  move_rotate.c \
			  move_swap.c \
			  parse_checks.c \
			  parsing.c \
			  print_opt.c \
			  simple_sort.c \
			  sorting.c \
			  utils_sorting.c

SRC			= $(COMMON_SRC) main.c

SRC_BONUS	= $(COMMON_SRC) \
			  __bonus_checker.c \
			  __checker_utils.c \
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
