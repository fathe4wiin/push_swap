NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC			= error.c \
			  ft_atol.c \
			  ft_split.c \
			  ft_utils.c \
			  indexing.c \
			  lists.c \
			  main.c \
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

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean

.SECONDARY: $(OBJS) $(BOBJS)
