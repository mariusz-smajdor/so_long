NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
MAKEFLAGS += -s

SRCS = main.c
OBJS = $(SRCS:.c=.o)

LIB_DIRS = libs/libft libs/ft_printf
LIBS = ft ftprintf
LDFLAGS_LIBS = $(addprefix -L, $(LIB_DIRS)) $(addprefix -l, $(LIBS))

all: $(LIBS) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LDFLAGS_LIBS) -o $@
	$(MAKE) clean

$(LIBS):
	$(foreach dir, $(LIB_DIRS), make -C $(dir);)

clean:
	$(RM) $(OBJS)
	$(foreach dir, $(LIB_DIRS), $(RM) $(dir)/*.a)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
