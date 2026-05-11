NAME        := claptrap
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

SRCS        := main.cpp ClapTrap.cpp
OBJS        := $(SRCS:.cpp=.o)

# Colors
GREEN       := \033[0;32m
CYAN        := \033[0;36m
RESET       := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)[Linking]$(RESET) $(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Build successful$(RESET)"

%.o: %.cpp
	@echo "$(GREEN)[Compiling]$(RESET) $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "$(CYAN)Cleaned objects$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)Removed executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re