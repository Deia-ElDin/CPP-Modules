NAME = phonebook

CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes

SRC = main.cpp Contact.cpp PhoneBook.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re