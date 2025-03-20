CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp ScalarConverter.cpp
OBJF = $(SRCF:.cpp=.o)
NAME = ./convert

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp ScalarConverter.hpp
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all
