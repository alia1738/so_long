.cf = main.c read_map.c simple_helpers.c character_moves.c map_checks.c itoa.c animation.c image.c simple_helpers2.c animation_t.c
.of = $(.cf:.c=.o)
.df = $(.of:.o=.d)
LINK_GNL = -Lgnl -lgnl
LINK_MINILIBX = -Lminilibx -lmlx -framework OpenGL -framework AppKit 
CC = gcc
CFLAGS = -Werror -Wextra -Wall -Iminilibx
NAME = so_long

all: $(NAME)
-include $(addprefix dep/,$(.df))

$(NAME): obj dep $(addprefix obj/,$(.of))
	$(MAKE) -sC gnl all
	$(MAKE) -sC minilibx all
	$(CC) $(addprefix obj/,$(.of)) $(LINK_GNL) $(LINK_MINILIBX) -o $(NAME)

obj/%.o: src/%.c src/so_long_bonus.h
	$(CC) -c $(CFLAGS) $< -o $@ -MD -MF $(@:obj/%.o=dep/%.d)

clean:
	$(MAKE) -sC gnl clean
	$(MAKE) -sC minilibx clean
	rm -rf $(addprefix obj/,$(.of)) $(addprefix dep/,$(.df)) obj dep

fclean: clean
	$(MAKE) -sC gnl fclean
	rm -f $(NAME)

re: fclean $(NAME)

obj:
	mkdir obj
dep:
	mkdir dep