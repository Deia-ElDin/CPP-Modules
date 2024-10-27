NAME = prog

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

SRC = main.cpp src/Utils.cpp src/Bureaucrat.cpp src/AForm.cpp \
	src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp \
	src/PresidentialPardonForm.cpp src/Intern.cpp

HPP_SRC = includes/Bureaucrat.hpp includes/Form.hpp includes/Utils.hpp \
	includes/ShrubberyCreationForm.hpp includes/RobotomyRequestForm/hpp \
	includes/PresidentialPardonForm.hpp includes/Intern.hpp

OBJ = $(SRC:.cpp=.o) 

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

run: $(NAME) clean
	@./$(NAME)

%.o: %.cpp $(HPP_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
