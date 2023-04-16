CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a

SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	@rm -f $(OBJECTS) $(BONUSOBJECTS)

fclean:
	@rm -f $(NAME) $(OBJECTS) $(BONUSOBJECTS)

re:	fclean all

.PHONY : all clean fclean re
