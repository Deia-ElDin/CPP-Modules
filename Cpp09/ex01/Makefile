NAME = RPN

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

HPP_SRC = includes/RPN.hpp includes/Utils.hpp

CPP_SRCS = main.cpp src/RPN.cpp src/Utils.cpp

OBJS = $(CPP_SRCS:.cpp=.o)

Eq = "1 4 %"

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HPP_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

run: $(NAME) clean
	@./$(NAME) $(Eq)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re
