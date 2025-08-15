CC = cc -Wall -Wextra -Werror -MMD -MP

FILE_NAMES =	get_next_line_bonus \
				get_next_line_utils_bonus


SRC_PATH = src
OBJ_PATH = obj
HEA_PATH = include

SRC_FILES = $(FILE_NAMES:%=$(SRC_PATH)/%.c)
OBJ_FILES = $(FILE_NAMES:%=$(OBJ_PATH)/%.o)
DEP_FILES = $(OBJ_FILES:.o=.d)
HEA_FILES = $(HEA_PATH)/get_next_line_bonus.h

INCLUDE = -I $(HEA_PATH) -I ../libft/include

NAME = libgnl.a

.PHONY: all clean fclean re

all : $(NAME)


$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HEA_FILES) | $(OBJ_PATH)
	$(CC) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ_FILES)
	@$(MAKE) -C ../libft
	ar rcs $(NAME) $(OBJ_FILES)


clean :
	rm -f $(OBJ_FILES) $(DEP_FILES)


fclean : clean
	rm -f $(NAME) 


re : fclean all

# Inclusion automatique des fichiers .d s’ils existent
-include $(DEP_FILES)