CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp PhoneBook.cpp Contact.cpp
OBJF = $(SRCF:.cpp=.o)
NAME = ./phonebook

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp Contact.hpp PhoneBook.hpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all

.PHONY : all clean fclean re
