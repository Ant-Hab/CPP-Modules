NAME        := scavtrap

# Compiler and Flags
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

# Directories
SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := include

# Source and Object Files
SRCS        := main.cpp \
               $(SRC_DIR)/ClapTrap.cpp \
               $(SRC_DIR)/ScavTrap.cpp

# This complex OBJS logic handles both root and src files correctly
OBJS        := $(OBJ_DIR)/main.o \
               $(OBJ_DIR)/ClapTrap.o \
               $(OBJ_DIR)/ScavTrap.o

# Includes
INC         := -I$(INC_DIR)

# Colors
GREEN       := \033[0;32m
CYAN        := \033[0;36m
RESET       := \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)[Linking]$(RESET) $(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Build successful!$(RESET)"

# Rule for main.cpp in root
$(OBJ_DIR)/main.o: main.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)[Compiling]$(RESET) $<"
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

# Rule for files in src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)[Compiling]$(RESET) $<"
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)Cleaned objects$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)Removed executable$(RESET)"

re: fclean all

.PHONY: all clean fclean re