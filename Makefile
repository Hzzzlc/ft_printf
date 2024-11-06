NAME = libftprintf.a

CC = CC

AR = ar

ARFLAGS = rcs

CFILES = ft_printf.c ft_void.c ft_unsigned_int.c ft_strlen.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_hex_min.c ft_hex_mayus.c

HEADER_DIR = ./includes

OBJ = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I $(HEADER_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJ)
	@echo "Compiling $(NAME) and creating object files..."
	ar rcs $(NAME) $(OBJ)

clean:
	@echo "Removing object files..."
	@rm -f $(OBJ)
fclean: clean
	@echo "Removing $(NAME) .exe..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


