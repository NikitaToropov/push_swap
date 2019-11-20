NAME_PS = push_swap

INCLUDES = ./includes
HEADER = $(INCLUDES)/push_swap.h

# dirs
DIR_S = srcs
DIR_O = objs

# files
C_FILES = ft_atoi.c\
		stack_operations.c\
		string_parse.c\
		stack_alloc_and_free.c\

SRCS_PS = $(addprefix $(DIR_S)/,$(C_FILES))
OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME_PS)

$(NAME_PS): $(DIR_O) $(OBJS)
	$(CC) $(FLAGS) main.c $(OBJS) -I $(INCLUDES) -o $@

$(DIR_O):
	mkdir -p objs

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)
	$(CC) $(FLAGS) -I $(INCLUDES) -c ./$< -o $@

clean:
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all