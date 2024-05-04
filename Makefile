NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
MAKEFLAGS += -s

SRCS = main.c
OBJS = $(SRCS:.c=.o)

INCLUDE_DIRS = includes/libft includes/ft_printf
INCLUDES = ft ftprintf
LDFLAGS_LIBS = $(addprefix -L, $(INCLUDE_DIRS)) $(addprefix -l, $(INCLUDES))

all: $(INCLUDES) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LDFLAGS_LIBS) -o $@
	$(MAKE) clean

$(INCLUDES):
	$(foreach dir, $(INCLUDE_DIRS), make -C $(dir);)

clean:
	$(RM) $(OBJS)
	$(foreach dir, $(INCLUDE_DIRS), $(RM) $(dir)/*.a)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
