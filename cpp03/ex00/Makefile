# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 22:32:10 by kanahash          #+#    #+#              #
#    Updated: 2025/08/02 22:32:15 by kanahash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
SRCS =main.cpp ClapTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
