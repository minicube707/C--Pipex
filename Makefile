
CC = cc -Wall -Wextra -Werror -MMD -MP -g

FILE_NAMES =	check_command \
                check_file \
                check_nb_quote \
                copy_pipe \
                execute \
                free_all \
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
DEP_FILES = $(OBJ_FILES:.o=.d)  # <- fichiers .d générés automatiquement
HEA_FILES = $(HEA_PATH)/pipex.h


NAME = pipex

.PHONY: all clean fclean re bonus

all : $(NAME)

$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEA_FILES) | $(OBJ_PATH)
	$(CC) -I$(HEA_PATH)  -Ilibft -Ift_printf -O3 -c $< -o $@


$(NAME): $(OBJ_FILES) 
	@$(MAKE) -C libft
	$(CC) $(OBJ_FILES)  -Llibft -lft -o $(NAME)



clean :
	@$(MAKE) -C libft clean
	rm -f $(OBJ_FILES) $(DEP_FILES)

fclean : clean	
	@$(MAKE) -C libft fclean
	rm -f $(NAME)

re : fclean all

# Inclusion automatique des fichiers .d s’ils existent
-include $(DEP_FILES)
