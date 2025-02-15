NAME = prog

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

HPP_SRC = includes/Utils.hpp includes/easyfind.hpp

CPP_SRCS = main.cpp src/Utils.cpp 

OBJS = $(CPP_SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HPP_SRCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

run: $(NAME) clean
	@./$(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re
