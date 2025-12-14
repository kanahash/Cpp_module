# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/14 22:04:20 by kanahash          #+#    #+#              #
#    Updated: 2025/12/14 22:04:22 by kanahash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -I./includes
SRCS = srcs/main.cpp srcs/Contact.cpp srcs/PhoneBook.cpp 

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
