CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.c PhoneBook.cpp PhoneBook.hpp
OBJF = $(SRCF:.c=.o)
NAME = ./phonebook

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "🚀 Mission is complete!"

%.o : %.c ./Contact.hpp ./PhoneBook.hpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all

.PHONY : all clean fclean re
