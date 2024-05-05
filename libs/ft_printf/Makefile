NAME		= libftprintf.a
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f
MAKEFLAGS	+= -s

SRCS		= ft_printf.c format_specifiers/print_char.c format_specifiers/print_hex.c \
				format_specifiers/print_number.c format_specifiers/print_pointer.c \
				format_specifiers/print_string.c format_specifiers/print_unsigned_number.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs -o $(NAME) $(OBJS)
	$(MAKE) clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
