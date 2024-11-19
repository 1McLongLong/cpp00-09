CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJF = $(SRCF:.cpp=.o)
NAME = ./FragTrap

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all

.PHONY : all clean fclean re
