CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp newZombie.cpp Zombie.cpp randomChump.cpp
OBJF = $(SRCF:.cpp=.o)
NAME = ./braiinz

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp Zombie.hpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all

.PHONY : all clean fclean re
