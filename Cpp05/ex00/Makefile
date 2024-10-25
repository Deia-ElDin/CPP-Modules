NAME = prog

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

SRC = main.cpp src/Utils.cpp src/Bureaucrat.cpp

HPP_SRC = includes/Bureaucrat.hpp includes/Utils.hpp

OBJ = $(SRC:.cpp=.o) 

# OBJ = main.o src/Utils.o src/Bureaucrat.o
# This does not build the object files. It just prepares a list of object file names that will be used later (e.g., in the linking step).

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
# Linking proccess
# -o: Ensures that the executable is named prog

all: $(NAME)

run: $(NAME) clean
	@./$(NAME)

%.o: %.cpp $(HPP_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compiling proccess
# -c: Tells the compiler to generate a .o file (object file) without linking.
# $<: The current .cpp file being compiled.
# $@: The output file (the corresponding .o file).
# -o: Ensures that the object file has the correct name

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
