NAME = libftprintf.a
SOURCES =
OBJECTS = $(SOURCES:.c=.o)

AR = ar
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
