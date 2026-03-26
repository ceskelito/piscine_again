NAME      = ft_display_file
CC        = gcc
MKDIR     = mkdir -p
RM        = rm -f
CFLAGS    = -Wall -Wextra -Werror
# IFLAGS    = -Iincludes

FILES     = main

SRCS_DIR  = srcs
OBJS_DIR  = objs

SRCS      = $(addsuffix .cpp, $(FILES))
OBJS      = $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(FILES)))

vpath %.c $(SRCS_DIR)

all: $(NAME)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) -c $(IFLAGS) $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(CC) $^ -o $@

$(OBJS_DIR):
	$(MKDIR) $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
