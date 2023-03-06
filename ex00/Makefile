NAME = convert
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
LDFLAGS = 
SRCS = main.cpp \
	ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
