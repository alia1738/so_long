.cf = main.c read_map.c simple_helpers.c character_moves.c map_checks.c itoa.c image.c simple_helpers2.c
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
	@$(MAKE) -sC gnl all
	@$(MAKE) -sC minilibx all
	@printf "\x1B[33m"
	$(CC) $(addprefix obj/,$(.of)) $(LINK_GNL) $(LINK_MINILIBX) -o $(NAME)
	@printf "\x1B[0m"

obj/%.o: src/%.c src/so_long.h
	@printf "\x1B[36m"
	$(CC) -c $(CFLAGS) $< -o $@ -MD -MF $(@:obj/%.o=dep/%.d)
	@printf "\x1B[0m"

clean:
	@$(MAKE) -sC gnl clean
	@$(MAKE) -sC minilibx clean
	@printf "\x1B[31m"
	rm -rf $(addprefix obj/,$(.of)) $(addprefix dep/,$(.df)) obj dep
	@printf "\x1B[0m"

fclean: clean
	@$(MAKE) -sC gnl fclean
	@printf "\x1B[31m"
	rm -f $(NAME)
	@printf "\x1B[0m"

re: fclean $(NAME)

obj:
	@mkdir obj
dep:
	@mkdir dep