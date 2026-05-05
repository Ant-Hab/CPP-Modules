NAME        := violence

# Compiler and Flags
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

# Directories
INC_DIR     := .
OBJ_DIR     := obj

# Source Files
SRCS        := main.cpp \
               Weapon.cpp \
               HumanA.cpp \
               HumanB.cpp

# Object Files (Stored in obj/ directory)
OBJS        := $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# Colors for pretty output
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
CYAN        := \033[0;36m
RESET       := \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)[Linking]$(RESET) $(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ $(NAME) built successfully!$(RESET)"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(GREEN)[Compiling]$(RESET) $<"
	@$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@echo "$(YELLOW)[Cleaning]$(RESET) object files"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)[Removing]$(RESET) $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re