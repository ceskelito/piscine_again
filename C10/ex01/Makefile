NAME      = ft_cat
CC        = gcc
MKDIR     = mkdir -p
RM        = rm -f
CFLAGS    = -Wall -Wextra -Werror

SRCS = ft_cat.c
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(IFLAGS) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
