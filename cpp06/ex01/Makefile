CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp Serializer.cpp 
OBJF = $(SRCF:.cpp=.o)
NAME = ./Serializer

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp Serializer.hpp
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋🧏"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋🧏"

re: fclean all
