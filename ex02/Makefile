NAME = Base
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
LDFLAGS = 
SRCS = main.cpp \
	Base.cpp \
	A.cpp \
	B.cpp \
	C.cpp
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
