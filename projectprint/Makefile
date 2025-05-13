NAME = libftprintf.a
SOURCES = ft_print.c parsing.c tools.c \
			type_processing.c type_processing_hex.c
OBJECTS = $(SOURCES:.c=.o)

AR = ar
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
