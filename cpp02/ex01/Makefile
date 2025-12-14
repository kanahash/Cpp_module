# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kanahash <kanahash@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 17:08:16 by kanahash          #+#    #+#              #
#    Updated: 2025/07/25 17:08:18 by kanahash         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Fixed

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
SRCS =main.cpp Fixed.cpp

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
