NAME        := brain

# Compiler and Flags (Strict 42 requirements)
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

# Sources and Objects
SRCS        := main.cpp
OBJS        := $(SRCS:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Standard pattern rule for compiling .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re