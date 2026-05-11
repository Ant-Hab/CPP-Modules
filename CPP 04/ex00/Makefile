NAME        := polymorphism

# Compiler and Flags
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

# Directories
SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := include

# Source and Object Files
SRCS        := main.cpp \
               $(SRC_DIR)/Animal.cpp \
               $(SRC_DIR)/Dog.cpp \
               $(SRC_DIR)/Cat.cpp \
               $(SRC_DIR)/WrongAnimal.cpp \
               $(SRC_DIR)/WrongCat.cpp

OBJS        := $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

# Includes
INC         := -I$(INC_DIR)

# Colors
GREEN       := \033[0;32m
YELLOW      := \033[0;33m
CYAN        := \033[0;36m
RESET       := \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)[Linking]$(RESET) $(NAME)"
	@$(CXX) $(CXXFLAGS) $(INC) $(OBJS) -o $(NAME)
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