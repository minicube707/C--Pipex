CC = cc -Wall -Wextra -Werror -MMD -MP

FILE_NAMES = ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper      

SRC_PATH = src
OBJ_PATH = obj
HEA_PATH = include

SRC_FILES = $(FILE_NAMES:%=$(SRC_PATH)/%.c)
OBJ_FILES = $(FILE_NAMES:%=$(OBJ_PATH)/%.o)
DEP_FILES = $(OBJ_FILES:.o=.d)
HEA_FILES = $(HEA_PATH)/libft.h

INCLUDE = -I $(HEA_PATH)

NAME = libft.a

.PHONY: all clean fclean re

all : $(NAME)

$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c $(HEA_FILES) | $(OBJ_PATH)
	$(CC) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)


clean :
	rm -f $(OBJ_FILES) $(DEP_FILES)
	

fclean : clean
	rm -f $(NAME) 


re : fclean all

# Inclusion automatique des fichiers .d s’ils existent
-include $(DEP_FILES)