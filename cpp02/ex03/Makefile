CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJF = $(SRCF:.cpp=.o)
NAME = ./Fixed

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp Fixed.hpp Point.hpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all

.PHONY : all clean fclean re
