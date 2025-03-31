CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp 
OBJF = $(SRCF:.cpp=.o)
NAME = ./easyfind

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp easyfind.hpp
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋🧏"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋🧏"

re: fclean all
