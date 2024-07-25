CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJF = $(SRCF:.cpp=.o)
NAME = ./braiinz

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp HumanA.hpp HumanB.hpp Weapon.hpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all

.PHONY : all clean fclean re
