NAME_PS = push_swap

INCLUDES = ./includes
HEADER = $(INCLUDES)/ft_printf.h

# dirs
DIR_S = push_swap
DIR_O = objs_ps

# files
C_FILES = 

SRCS_PS = $(addprefix $(DIR_S)/,$(C_FILES))
OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME_PS)

$(NAME_PS): $(DIR_O) $(OBJS)
	$(CC) $(FLAGS) main.c -I $(INCLUDES) -o $(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_O)
	mkdir -p objs_ps

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)
	$(CC) $(FLAGS) -I $(INCLUDES) -c ./$< -o $@

clean:
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all