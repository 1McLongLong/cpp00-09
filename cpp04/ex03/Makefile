CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = Ice.cpp Cure.cpp main.cpp AMateria.cpp Character.cpp MateriaSource.cpp   
OBJF = $(SRCF:.cpp=.o)
NAME = ./inter

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp Ice.hpp Cure.hpp AMateria.hpp Character.hpp ICharacter.hpp MateriaSource.hpp IMateriaSource.hpp
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all
