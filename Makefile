
CC = cc -Wall -Wextra -Werror

FILE_NAMES = parsing_argument \
			pipex \
			stack \
			parsing_environnement \
			free_all \
			parsing_command \
			super_list \
			tab_utils \
			execute \
			check_command
			
				
SRC_PATH = .
OBJ_PATH = .
HEA_PATH = .

SRC_FILES = $(FILE_NAMES:%=$(SRC_PATH)/%.c)
OBJ_FILES = $(FILE_NAMES:%=$(OBJ_PATH)/%.o)
HEA_FILES = $(HEA_PATH)/push_swap.h

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
