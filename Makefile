
CC = cc -Wall -Wextra -Werror

FILE_NAMES =	check_command \
                check_nb_quote \
                execute \
                free_all \
                parsing_argument \
                parsing_command \
                parsing_environnement \
                pipex \
                split_command \
                stack \
                super_list \
                tab_utils \
			
				
SRC_PATH = src
OBJ_PATH = obj
HEA_PATH = include

SRC_FILES = $(FILE_NAMES:%=$(SRC_PATH)/%.c)
OBJ_FILES = $(FILE_NAMES:%=$(OBJ_PATH)/%.o)
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
	rm -f $(OBJ_FILES)

fclean : clean	
	@$(MAKE) -C libft fclean
	rm -f $(NAME)

re : fclean all

get_file:
	find src -type f -name '*.c' | sort | sed -E 's|.*/||; s/\.c$$/ \\/; s/^/\t\t/'
