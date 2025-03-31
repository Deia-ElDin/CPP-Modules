NAME = PmergeMe

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

HPP_SRC = includes/PmergeMe.hpp includes/Utils.hpp

CPP_SRCS = main.cpp src/PmergeMe.cpp src/Utils.cpp

OBJS = $(CPP_SRCS:.cpp=.o)

ARGS = 3 2 1

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HPP_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

generate_numbers:
	@jot -r 3000 1 2147483647 | tr '\n' ' ' > numbers.txt

all: $(NAME)

run: $(NAME) clean generate_numbers
	@./$(NAME) $$(cat numbers.txt)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re

# $$ means "pass a literal $ to the shell" and is used to escape the special meaning of $ so it's interpreted by the shell instead of by Make.
# literal means that the character is used as it is, without any special meaning.