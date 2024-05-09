MAKEFLAGS += -s
NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

UTILS = utils/error.c utils/map_width.c utils/map_height.c
SRCS = main.c parse_map.c validate_map/validate_map.c validate_map/check_characters.c validate_map/check_shape.c \
		validate_map/check_border.c start_game/start_game.c start_game/fill_textures.c start_game/events.c $(UTILS)
OBJS = $(SRCS:.c=.o)

LIB_DIRS = libs/libft libs/ft_printf
LIBS = ft ftprintf
LDFLAGS_LIBS = $(addprefix -L, $(LIB_DIRS)) $(addprefix -l, $(LIBS))

all: $(LIBS) $(NAME)

$(LIBS):
	$(foreach dir, $(LIB_DIRS), make -C $(dir);)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LDFLAGS_LIBS) -o $@
	$(MAKE) clean

clean:
	$(RM) $(OBJS)
	$(foreach dir, $(LIB_DIRS), $(RM) $(dir)/*.a)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re
