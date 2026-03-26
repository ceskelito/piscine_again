NAME      = ft_display_file
CC        = gcc
MKDIR     = mkdir -p
RM        = rm -f
CFLAGS    = -Wall -Wextra -Werror

SRCS = main.c
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
