CC = cc
CFLAGS = -Wall -Wextra -Werror

FILE_NAMES = ft_isalpha ft_isalnum ft_isdigit ft_isascii ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd 


SRC_FILES = $(FILE_NAMES:%=%.c)
OBJ_FILES = $(FILE_NAMES:%=%.o)
HEA_FILES = libft.h

BON_NAMES = ft_lstlast_bonus ft_lstadd_back_bonus ft_lstadd_front_bonus ft_lstclear_bonus ft_lstdelone_bonus ft_lstiter_bonus ft_lstmap_bonus ft_lstnew_bonus ft_lstsize_bonus 
BON_OBJ = $(BON_NAMES:%=%.o)

NAME = libft.a

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

bonus : $(BON_OBJ) $(OBJ_FILES)
	ar rcs $(NAME) $(BON_OBJ) $(OBJ_FILES)
