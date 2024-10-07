CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = ./src/Ice.cpp ./src/Cure.cpp ./src/main.cpp ./src/AMateria.cpp ./src/Character.cpp ./src/MateriaSource.cpp   
OBJF = $(SRCF:.cpp=.o)
NAME = ./inter

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp ./inc/Ice.hpp ./inc/Cure.hpp ./inc/AMateria.hpp ./inc/Character.hpp ./inc/ICharacter.hpp ./inc/MateriaSource.hpp ./inc/IMateriaSource.hpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all

.PHONY : all clean fclean re
