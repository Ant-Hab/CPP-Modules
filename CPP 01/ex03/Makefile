NAME        := violence

# Compiler and Flags
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

# Directories
SRC_DIR     := src
INC_DIR     := include
OBJ_DIR     := obj

# Source Files (main is in root, others in src/)
SRCS        := main.cpp \
               $(SRC_DIR)/Weapon.cpp \
               $(SRC_DIR)/HumanA.cpp \
               $(SRC_DIR)/HumanB.cpp

# Object Files (Stored in obj/ directory)
OBJS        := $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# Includes (-I tells the compiler where to look for .hpp files)
INC         := -I$(INC_DIR)

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
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	@echo "$(YELLOW)[Cleaning]$(RESET) object files"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)[Removing]$(RESET) $(NAME)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re