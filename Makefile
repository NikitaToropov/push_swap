NAME_PS = push_swap
NAME_CH = checker

LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a
INC_PSW = ./includes

HEADER_PSW = $(INC_PSW)/push_swap.h

# dirs
DIR_S = srcs
DIR_O = objs

# files
C_FILES = ft_it_is_sorted.c\
		string_parse.c\
		stack_alloc_and_free.c\
		ft_push_in_first.c\
		stack_operations.c\
		ft_new_sorting.c\
		ops_alloc_analyze_free.c\
		ft_do_ops.c\
		ft_smart_insert_sort.c\

SRCS = $(addprefix $(DIR_S)/,$(C_FILES))
OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra
INC_LIBS = -L $(LIB_DIR) -lft
INC_HEADERS = -I $(INC_PSW) -I $(LIB_DIR)

.PHONY: all clean fclean re lib

all: $(NAME_PS) $(NAME_CH)

$(NAME_PS): $(DIR_O) $(LIB) $(OBJS) push_swap.c
	$(CC) $(FLAGS) $(OBJS) $(INC_HEADERS) $(INC_LIBS) push_swap.c -o $@

$(NAME_CH): $(DIR_O) $(LIB) $(OBJS) checker.c
	$(CC) $(FLAGS) $(OBJS) $(INC_HEADERS) $(INC_LIBS) checker.c -o $@

$(DIR_O):
	mkdir -p objs

$(LIB):
	make -C ./libft

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER_PSW)
	$(CC) $(FLAGS) -I $(INC_PSW) -I $(LIB_DIR) -c ./$< -o $@

clean:
	rm -rf $(DIR_O)
	make -C ./libft fclean

fclean: clean
	rm -f $(NAME_PS)
	rm -f $(NAME_CH)

re: fclean all