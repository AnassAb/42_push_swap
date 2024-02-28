CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = check_params.c ft_atoi.c ft_split.c lis.c operations.c push_swap.c median.c sort_stack.c sorting_utils.c sorting_utils2.c stack_utils.c stack_utils2.c
OBJS = $(SRCS:.c=.o)
HFILE = push_swap.h
NAME = push_swap
BSRCS = check_params.c ft_atoi.c ft_split.c bonus/checker_bonus.c bonus/operations_bonus.c bonus/checker_utils_bonus.c bonus/stack_utils_bonus.c bonus/stack_utils2_bonus.c bonus/gnl/get_next_line.c bonus/gnl/get_next_line_utils.c
BOBJS = $(BSRCS:.c=.o)
BHFILE = bonus/checker_bonus.h
CHECK = checker

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c $(HFILE)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(CHECK)

$(CHECK): $(BOBJS) $(BHFILE)
	$(CC) $(CFLAGS) $(BOBJS) -o $@

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME) $(CHECK)

re: fclean all