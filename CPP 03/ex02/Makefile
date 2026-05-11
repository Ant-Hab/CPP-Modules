NAME        := fragtrap

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := include

SRCS        := main.cpp \
               $(SRC_DIR)/ClapTrap.cpp \
               $(SRC_DIR)/ScavTrap.cpp \
               $(SRC_DIR)/FragTrap.cpp

OBJS        := $(OBJ_DIR)/main.o \
               $(OBJ_DIR)/ClapTrap.o \
               $(OBJ_DIR)/ScavTrap.o \
               $(OBJ_DIR)/FragTrap.o

INC         := -I$(INC_DIR)

GREEN       := \033[0;32m
CYAN        := \033[0;36m
RESET       := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN)[Linking]$(RESET) $(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Build successful!$(RESET)"

$(OBJ_DIR)/main.o: main.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re