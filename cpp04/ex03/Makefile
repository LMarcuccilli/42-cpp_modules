#							COLORS	#

GREEN   = \033[1;32m
YELLOW  = \033[1;33m
RED     = \033[1;31m
BLUE    = \033[1;34m
RESET   = \033[0m

#							PATHS	#

OBJ_DIR		=	.obj/
SRC_DIR		=	src/
INC_DIR		=	include/

#							FILES	#

SRC_FILES	=	main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

NAME		=	materia

#							COMPILER	#

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -Wshadow -std=c++98 -I $(INC_DIR)

#							RULES	#

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Build successful -> $(NAME)$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Compiling $@...$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing executable...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re print_flags
