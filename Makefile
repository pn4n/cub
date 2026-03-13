NAME = cub

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c window.c

OBJDIR = obj

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

DEPS = defines.h header.h

# MLX_F = -Lmlx -L/usr/lib -Imlx_linux -lmlx -lX11
# MLX_C =  -I/usr/include -Imlx_linux -O3 
# MKX_DIR = minilibx-linux

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS) $(DEPS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(MLX_F) -o $(NAME)

# $(OBJDIR)/%.o: %.c
# 	mkdir -p $(OBJDIR)
# 	$(CC) $(CFLAGS) $(MLX_C) -c $< -o $@


norm:
	norminette $(SRCS) $(DEPS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	
re: fclean all