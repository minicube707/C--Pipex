
CC = cc -Wall -Wextra -Werror -MMD -MP

FILE_NAMES =	check_command \
                check_nb_quote \
                copy_pipe \
                execute \
                here_doc \
                manage_error \
                parsing_argument \
                parsing_command \
                parsing_environnement \
                pipex \
                split_command \
                split_command_utils \
                stack \
                stack_utils \
                super_list \
                super_list_utils \
                tab_utils \
                tab_utils_utils \
			
				
SRC_PATH = src
OBJ_PATH = obj
HEA_PATH = include

SRC_FILES = $(FILE_NAMES:%=$(SRC_PATH)/%.c)
OBJ_FILES = $(FILE_NAMES:%=$(OBJ_PATH)/%.o)
DEP_FILES = $(OBJ_FILES:.o=.d)
HEA_FILES = $(HEA_PATH)/pipex.h

INCLUDE = -I $(HEA_PATH) -I libft/include -I gnl/include
ARCHIVE = -L libft -l ft -L gnl -l gnl

NAME = pipex

.PHONY: all clean fclean re

all : $(NAME)

$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEA_FILES) | $(OBJ_PATH)
	$(CC) $(INCLUDE) -O3 -c $< -o $@


$(NAME): $(OBJ_FILES)
	@$(MAKE) -C libft 
	@$(MAKE) -C gnl
	$(CC) $(OBJ_FILES)  $(ARCHIVE) -o $(NAME)



clean :
	@$(MAKE) -C libft clean
	@$(MAKE) -C gnl clean
	rm -f $(OBJ_FILES) $(DEP_FILES)

fclean : clean	
	@$(MAKE) -C libft fclean
	@$(MAKE) -C gnl fclean
	rm -f $(NAME)

re : fclean all

# Inclusion automatique des fichiers .d s’ils existent
-include $(DEP_FILES)
