NAME        := intern_factory

CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++20

SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := include

SRCS        := main.cpp \
               $(SRC_DIR)/Bureaucrat.cpp \
               $(SRC_DIR)/AForm.cpp \
               $(SRC_DIR)/ShrubberyCreationForm.cpp \
               $(SRC_DIR)/RobotomyRequestForm.cpp \
               $(SRC_DIR)/PresidentialPardonForm.cpp \
               $(SRC_DIR)/Intern.cpp

OBJS        := $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
INC         := -I$(INC_DIR)

GREEN       := \033[0;32m
YELLOW      := \033[0;33m
CYAN        := \033[0;36m
RESET       := \033[0m

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
	@rm -f $(NAME) \
	       *_shrubbery

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: