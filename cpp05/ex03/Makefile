CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp
OBJF = $(SRCF:.cpp=.o)
NAME = ./Intern

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all
