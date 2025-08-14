CC = cc
CFLAGS = -Wall -Wextra -Werror

FILE_NAMES =	get_next_line_bonus \
				get_next_line_utils_bonus


SRC_FILES = $(FILE_NAMES:%=%.c)
OBJ_FILES = $(FILE_NAMES:%=%.o)
HEA_FILES = get_next_line_bonus.h

NAME = libgnl.a

.PHONY: all clean fclean re bonus

all : $(NAME)


$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)


%.o : %.c $(HEA_FILES)
	$(CC) -I $(CFLAGS) -c $< -o $@


clean :
	rm -f $(OBJ_FILES)
	rm -f $(BON_OBJ)


fclean : clean
	rm -f $(NAME) 


re : fclean all

