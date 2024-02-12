NAME	=	philo

SRC		=	main.c \
			lst_utils.c \
			utils.c \
			routine.c \
			behavior.c \
			monitor.c

OBJ		=	$(SRC:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
				clang $(CFLAGS) -g $(OBJ) -o $(NAME)

clean	:	
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
