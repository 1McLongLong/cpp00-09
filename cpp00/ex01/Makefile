# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 08:48:35 by touahman          #+#    #+#              #
#    Updated: 2024/09/16 09:05:36 by touahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = main.cpp PhoneBook.cpp Contact.cpp
OBJF = $(SRCF:.cpp=.o)
NAME = ./phonebook

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀🚀🚀 Mission complete!"

%.o : %.cpp Contact.hpp PhoneBook.hpp
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all

.PHONY : all clean fclean re
