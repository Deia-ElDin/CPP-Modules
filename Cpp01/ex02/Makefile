Name = prog

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

$(Name): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(Name)

all: $(Name)

run: $(Name)
	@./$(Name)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re run
