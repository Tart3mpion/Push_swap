
NAME = push_swap

SRCS = main.c utils.c check_inputs.c \
initialization.c manage_errors.c pushandswap.c rotate.c \
compare.c sort_three.c push_swap.c quick_sort.c 

LIB = $(SRC_FOLDER)libft/

INCLUDES = /includes/
FLAGS = -I.$(INCLUDES) -I$(LIB) -Wall -Werror -Wextra
OBJS = $(SRCS:.c=.o)
CC = clang -g $(FLAGS)


all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB)
	$(CC) $(OBJS) -L$(LIB) -lft -o $(NAME)

clean :
	make clean -C $(LIB)
	rm $(OBJS)

fclean : clean
	make fclean -C $(LIB)
	rm $(NAME)

re : fclean all