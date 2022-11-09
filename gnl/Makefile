.cf = get_next_line.c get_next_line_utils.c
.of = $(.cf:.c=.o)
.df = $(.of:.o=.d)
flags = -Werror -Wextra -Wall
NAME = libgnl.a

all: $(NAME)
-include $(.df)

$(NAME): $(.of)
	@ar -rc $(NAME) $(.of)

%.o: %.c
	@gcc -c $(flags) -MD $< -o $@

clean:
	@rm -f $(.of) $(.df)

fclean:
	@rm -f $(NAME) $(.of) $(.df)

re: fclean $(NAME)
