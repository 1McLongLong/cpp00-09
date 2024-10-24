# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touahman <touahman@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 08:35:36 by touahman          #+#    #+#              #
#    Updated: 2024/09/16 08:48:15 by touahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCF = megaphone.cpp
OBJF = $(SRCF:.cpp=.o)
NAME = ./megaphone

all : $(NAME)

$(NAME): $(OBJF)
	@$(CC) $(FLAGS) $^ -o $@
	@echo "🚀 Mission is complete!"

%.o : %.cpp
	@$(CC) $(FLAGS) -c $< -o $@ 

clean:
	@rm -f $(OBJF)
	@echo "BYE BYE 👋"

fclean: clean
	@rm -f $(NAME)
	@echo "BYE BYE CPP👋"

re: fclean all

.PHONY : all clean fclean re
