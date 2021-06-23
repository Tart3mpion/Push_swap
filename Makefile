
NAME = push_swap

LIBFT = libft/libft.a

SRCS = main.c utils.c check_inputs.c \
initialization.c manage_errors.c swap.c rotate.c \
push.c compare.c sort_three.c push_swap.c sort_hundreds.c \
other-functions.c

FLAGS = -Wall -Werror -Wextra -I./libft -fsanitize=address -g
OBJS = $(SRCS:.c=.o)

CC = clang $(FLAGS)
LIBS = ./libft


all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBS)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBS)

clean :
	rm $(OBJS)
	make clean -C ./libft

fclean : clean
	rm $(NAME)

re : fclean all